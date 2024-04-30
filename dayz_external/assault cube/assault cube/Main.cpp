#include <iostream>
#include <Windows.h>
//yeyeyeye
#include "GameEngine.h"
#include "offsets.h"
#include "Memory.h"
#include "ConsoleMenu.h"

using namespace offsets;
using std::cout;
using std::endl;



MenuFeatureBool Brightness;
MenuFeatureFloat BrightnessLevel;
MenuFeatureBool NearTableCountBool;
MenuFeatureInt iNearTableCount;
MenuFeatureBool FarTableCountBool;
MenuFeatureInt iFarTableCount;
MenuFeatureBool BulletTable;
MenuFeatureInt iBulletTable;


void SetUpFt() {
	Brightness.title = "Brightness";
	Brightness.value = false;

	BrightnessLevel.title = "Brightness Level";
	BrightnessLevel.value = 10.0f;

	NearTableCountBool.value = false;
	BulletTable.value = false;
	FarTableCountBool.value = false;


	iNearTableCount.title = "Near Table";
	iNearTableCount.value = 0;


	iFarTableCount.title = "Far Table";
	iFarTableCount.value = 0;

	iBulletTable.title = "Bullet Table";
	iBulletTable.value = 0;
}




int main() {
	SetUpFt();

	ConsoleMenu menu;

	menu.addFeature(&Brightness);
	menu.addFeature(&BrightnessLevel);
	menu.addFeature(&iNearTableCount);
	menu.addFeature(&iFarTableCount);
	menu.addFeature(&iBulletTable);

	CDispatcher* mem = CDispatcher::Get();
	mem->Attach("DayZ_x64.exe");
	uint64_t base = mem->GetModuleBase("DayZ_x64.exe");
	uint64_t worldPtr = mem->ReadMemory<uint64_t>(base + xWorld);
	


	SetConsoleTitle("z3n1th");

	menu.printMenu();

	while (!GetAsyncKeyState(VK_NUMPAD0)) { 
		World world = mem->ReadMemory<World>(worldPtr);

		if(iNearTableCount.setValue(world.NearTableCount - 1)){
			menu.printMenu();
		}

		if (iFarTableCount.setValue(world.FarTableCount)) {
			menu.printMenu();
		}

		if (iBulletTable.setValue(world.BulletTableCount)) {
			menu.printMenu();
		}

		if (Brightness.value) {
			mem->WriteMemory<float>(worldPtr + offsetof(World, EyeAccom), BrightnessLevel.value);
		}
		else {
			mem->WriteMemory<float>(worldPtr + offsetof(World, EyeAccom), 1.0f);
		}
		Sleep(100);
		menu.update();
	}


	return 0;
}


//todo list
// 1. Add more features
// 2. Find more features
// 3. 