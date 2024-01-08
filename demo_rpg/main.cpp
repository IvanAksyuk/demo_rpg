#include <iostream>

#include "allclasses.h"


int main() {
	/*
	Warrior warr1;
	Wizard wiz1;
	Cleric cler1;
	Rogue rog1;

	std::cout << "Warrior\n"
		<< "-MaxHP: " << warr1.getMaxHP() << "\n"
		<< "-Stength: " << warr1.getStrength() << "\n"
		<< "-Intellect: " << warr1.getIntellect() << "\n";

	std::cout << "Wizard\n"
		<< "-MaxHP: " << wiz1.getMaxHP() << "\n"
		<< "-Stength: " << wiz1.getStrength() << "\n"
		<< "-Intellect: " << wiz1.getIntellect() << "\n";

	std::cout << "Cleric\n"
		<< "-MaxHP: " << cler1.getMaxHP() << "\n"
		<< "-Stength: " << cler1.getStrength() << "\n"
		<< "-Intellect: " << cler1.getIntellect() << "\n";

	std::cout << "Rogue\n"
		<< "-MaxHP: " << rog1.getMaxHP() << "\n"
		<< "-Stength: " << rog1.getStrength() << "\n"
		<< "-Intellect: " << rog1.getIntellect() << "\n";
		*/

	Cleric cler1;
	

	for (int i = 0; i < 2; i++) {
		std::cout 
			<< "Cleric\n"
			<< "-Level: " << cler1.getLevel() << "\n"
			<< "-EXP: " << cler1.getCurrentEXP() << "/" << cler1.getEXPToNextLevel()<<"\n"
			<< "-MaxHP: " << cler1.getMaxHP() << "\n"
			<< "-Strength: " << cler1.getStrength() << "\n"
			<< "-Intellect: " << cler1.getIntellect()  << "\n\n";
		cler1.gainEXP(100);

		
	}

	Warrior warr1;


	for (int i = 0; i < 2; i++) {
		std::cout
			<< "Warrior\n"
			<< "-Level: " << warr1.getLevel() << "\n"
			<< "-EXP: " << warr1.getCurrentEXP() << "/" << warr1.getEXPToNextLevel() << "\n"
			<< "-MaxHP: " << warr1.getMaxHP() << "\n"
			<< "-Strength: " << warr1.getStrength() << "\n"
			<< "-Intellect: " << warr1.getIntellect() << "\n\n";
		warr1.gainEXP(100);


	}
	return 0;
}