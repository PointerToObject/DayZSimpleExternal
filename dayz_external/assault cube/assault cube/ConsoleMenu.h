#pragma once
#include <Windows.h>
#include <iostream>
#include <string.h>
#include <vector>



using std::cout;
using std::endl;

struct MenuFeature {
	std::string title;

	virtual void update(){
		cout << title;

	}
	virtual void runAction(bool left) {

	}
};

struct MenuFeatureInt : MenuFeature {
	int value;


	void update() override {
		MenuFeature::update();
		cout << "\t\t: " << value;

	}

	bool setValue(int x) {
		bool result = value != x;
		value = x;
		return result;
	}

	void runAction(bool left) override {
		if (left) {
			value--;
		}
		else {
			value++;
		}
	}
};



struct MenuFeatureInt64 : MenuFeature {
	uint64_t value;


	void update() override {
		MenuFeature::update();
		cout << "\t: " << value;

	}

	bool setValue(uint64_t x) {
		bool result = value != x;
		value = x;
		return result;
	}

	void runAction(bool left) override {
		if (left) {
			value--;
		}
		else {
			value++;
		}
	}
};

struct MenuFeatureFloat : MenuFeature {
	float value;

	void update() override {
		MenuFeature::update();
		cout << "\t: " << value;

	}

	bool setValue(float x) {
		bool result = value != x;
		value = x;
		return result;
	}

	void runAction(bool left) override {
		if (left) {
			value--;
		}
		else {
			value++;
		}
	}
};

struct MenuFeatureBool : MenuFeature {
	bool value;

	void update() override {
		MenuFeature::update();
		cout << "\t\t: " << (value ? "true" : "false");

	}
	

	bool setValue(bool x) {
		bool result = value != x;
		value = x;
		return result;
	}

	void runAction(bool left) override {
		value = !value;
	}
};



class ConsoleMenu {
	std::vector<MenuFeature*> features;
	int selectedIndex;
public:
	ConsoleMenu() :
		selectedIndex(0)
	{
		
	}


	void addFeature(MenuFeature* mPtr) {
		features.push_back(mPtr);
	}

	void moveDown() {
		selectedIndex--;
		if (selectedIndex < 0) {
			selectedIndex = features.size() - 1;
		}
	}

	void moveUp() {
		selectedIndex++;
		if (selectedIndex > features.size() - 1) {
			selectedIndex = 0;
		}
	}
	
	void printMenu() {
		system("CLS");

		for (int i = 0; i < features.size(); i++) {


			MenuFeature* mPtr = features[i];
			mPtr->update();
			if (i == selectedIndex)
				cout << "\t\t<--";
			cout << endl;
		}
	}

	void update() {


		if (GetAsyncKeyState(VK_UP)) {
			moveDown();
			printMenu();
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			moveUp();
			printMenu();
		}

		if (GetAsyncKeyState(VK_LEFT)) {
			features[selectedIndex]->runAction(true);
			printMenu();
		}

		if (GetAsyncKeyState(VK_RIGHT)) {
			features[selectedIndex]->runAction(false);
			printMenu();
		}

	}

};

