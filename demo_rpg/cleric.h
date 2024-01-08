#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Cleric : public hp, public Statblock, public LevelSystem {

public:
	static const hptype HPGROWTH = (hptype)14;
	static const stattype BASESTR = (stattype)2;
	static const stattype BASEINT = (stattype)3;
	Cleric() : hp(HPGROWTH, HPGROWTH),
		Statblock(BASESTR, BASEINT)
	{}


private:

};