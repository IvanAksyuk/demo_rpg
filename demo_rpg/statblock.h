#pragma once

#include <cstdint>
typedef std::uint16_t stattype;
class Statblock {
	stattype Strength; // 0xFF
	stattype Intellect; //0xFF
public:	
	Statblock() :
		Strength((stattype)0), 
		Intellect((stattype)0) 
	{}
	explicit Statblock(stattype strength, stattype intellect):
		Strength(strength), 
		Intellect(intellect) 
	{}

	stattype getStrength() { return Strength; }
	stattype getIntellect() { return Intellect; }

protected:
	void increaseStats(stattype s, stattype i) {
		Strength += s;
		Intellect += i;
	}
};