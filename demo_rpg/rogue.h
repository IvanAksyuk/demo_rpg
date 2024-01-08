#pragma once
#include "hp.h"
#include "statblock.h"
class Rogue : public hp, public Statblock {

public:
	static const hptype HPGROWTH = (hptype)13;
	static const stattype BASESTR = (stattype)3;
	static const stattype BASEINT = (stattype)2;

	Rogue() : hp(HPGROWTH, HPGROWTH),
		Statblock(BASESTR, BASEINT)
	{}


private:

};