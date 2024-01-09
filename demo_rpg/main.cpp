#include <iostream>

#include "playercharacter.h"

int main() {
	
	PlayerCharacter p1(new Warrior());

	for (int i = 0; i < 2; i++) {
		std::cout
			<< p1.getClassName() << "\n"
			<< "-Level: " << p1.getLevel() << "\n"
			<< "-EXP: " << p1.getCurrentEXP() << "/" << p1.getEXPToNextLevel() << "\n"
			<< "-HP: " << p1.getCurrentHP() << "/" << p1.getMaxHP() << "\n"
			<< "-MP: " << p1.getCurrentMP() << "/" << p1.getMaxMP() << "\n"
			<< "-Strength: " << p1.getStrength() << "\n"
			<< "-Intellect: " << p1.getIntellect() << "\n"
			<< "-Agility: " << p1.getAgility() << "\n"
			<< "-Armor: " << p1.getArmor() << "\n"
			<< "-ElementRes: " << p1.getElementRes() << "\n";
			
		auto AllAbilities = p1.getAbilityList();
		std::cout << "-Abilities:\n";
		for (auto& ability : AllAbilities) {
			std::cout << " - " << ability.Name << "\n";
		}
		
		p1.gainEXP(100);
		p1.takeDamage(10);


		
	}


	return 0;
}