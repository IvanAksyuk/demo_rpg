#pragma once

#include <cstdint>
typedef std::uint16_t stattype;
class Statblock {
	stattype Strength; // 0xFF
	stattype Intellect; //0xFF
	stattype Agility; //0xFF
	stattype Armor;
	stattype ElementRes;
public:	
	explicit Statblock(
		stattype strength = 1, 
		stattype intellect = 1, 
		stattype agility = 1, 
		stattype armor = 0, 
		stattype elementres = 0):
		Strength(strength), 
		Intellect(intellect),
		Agility(agility),
		Armor(armor),
		ElementRes(elementres)
	{}

	stattype getStrength() { return Strength; }
	stattype getIntellect() { return Intellect; }
	stattype getAgility() { return Agility; }
	stattype getArmor() { return Armor; }
	stattype getElementRes() { return ElementRes; }

protected:
	void increaseStats(
		stattype s = 0, 
		stattype i = 0, 
		stattype a = 0, 
		stattype arm = 0, 
		stattype e =0  ) {
		Strength += s;
		Intellect += i;
		Agility += a;
		Armor += arm;
		ElementRes += e;

	}
};