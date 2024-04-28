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
MenuFeatureBool BulletTable;
MenuFeatureInt iBulletTable;

void SetUpFt() {
	Brightness.title = "Brightness";
	Brightness.value = false;

	BrightnessLevel.title = "Brightness Level";
	BrightnessLevel.value = 10.0f;

	NearTableCountBool.value = false;
	BulletTable.value = false;

	iNearTableCount.title = "Near Table";
	iNearTableCount.value = 0;

	iBulletTable.title = "Bullet Table";
	iBulletTable.value = 0;
}




int main() {
	SetUpFt();

	ConsoleMenu menu;

	menu.addFeature(&Brightness);
	menu.addFeature(&BrightnessLevel);
	menu.addFeature(&iNearTableCount);
	menu.addFeature(&iBulletTable);

	CDispatcher* mem = CDispatcher::Get();
	mem->Attach("DayZ_x64.exe");
	uint64_t base = mem->GetModuleBase("DayZ_x64.exe");
	uint64_t worldPtr = mem->ReadMemory<uint64_t>(base + xWorld);
	World world = mem->ReadMemory<World>(worldPtr);


	SetConsoleTitle("z3n1th");

	menu.printMenu();

	while (!GetAsyncKeyState(VK_NUMPAD0)) { 
		int btc = mem->ReadMemory<int>(worldPtr + (offsetof(World, BulletTableCount))); // Bullet Table Count
		int ntc = mem->ReadMemory<int>(worldPtr + (offsetof(World, NearTableCount)));   // Near Table Count
		if (ntc > 1) {
			iNearTableCount.value = ntc-1;
			menu.printMenu();
		}
		else {
			iNearTableCount.value = 0;
			menu.printMenu();
		}
		if (btc > 0) {
			iBulletTable.value = btc;
			menu.printMenu();
		}
		else {
			iBulletTable.value = 0;
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
// 1. fix the stuttering
// 2. reduce the ammount of if statements 
// 3. 