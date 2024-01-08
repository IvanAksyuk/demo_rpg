#pragma once
#include "hp.h"
#include "statblock.h"
class Wizard : public hp, public Statblock {

public:
	static const hptype HPGROWTH = (hptype)9;
	static const stattype BASESTR = (stattype)1;
	static const stattype BASEINT = (stattype)4;
	Wizard() : hp(HPGROWTH, HPGROWTH),
		Statblock(BASESTR, BASEINT)
	{}


private:

};