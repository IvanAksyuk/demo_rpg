#pragma once

#include "stattypes.h"
class Statblock {
	stattype Strength; // 0xFF
	stattype Intellect; //0xFF
public:	
	Statblock() :Strength((stattype)1), Intellect((stattype)1) {}
	explicit Statblock(stattype strength, stattype intellect):Strength(strength), Intellect(intellect) {}

	stattype getStrength() { return Strength; }
	stattype getIntellect() { return Intellect; }

};