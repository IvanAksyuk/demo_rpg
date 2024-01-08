#pragma once
#include "hp.h"
#include "statblock.h"
class Warrior : public hp, public Statblock {

public:
	static const hptype HPGROWTH = (hptype)19;
	static const stattype BASESTR = (stattype)4;
	static const stattype BASEINT = (stattype)1;
	Warrior() : hp(HPGROWTH, HPGROWTH),
		Statblock(BASESTR, BASEINT)
	{}


private:

};