#include <iostream>

#include "playercharacter.h"

int main() {
	
	PlayerCharacter p1(new Warrior());

	for (int i = 0; i < 2; i++) {
		std::cout 
			<< p1.getClassName()<<"\n"
			<< "-Level: " << p1.getLevel() << "\n"
			<< "-EXP: " <<p1.getCurrentEXP() << "/" << p1.getEXPToNextLevel()<<"\n"
			<< "-MaxHP: " <<p1.getCurrentHP()<<"/" << p1.getMaxHP() << "\n"
			<< "-Strength: " << p1.getStrength() << "\n"
			<< "-Intellect: " << p1.getIntellect()  << "\n\n";
		p1.gainEXP(100);
		p1.takeDamage(10);

		
	}


	return 0;
}