#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Wizard : public hp, public Statblock, public LevelSystem {

public:
	static const hptype BASEHP = (hptype)10;
	static const stattype BASESTR = (stattype)1;
	static const stattype BASEINT = (stattype)4;

	static const hptype HPGROWTH = (hptype)5;
	static const stattype STRGROWTH = (stattype)1;
	static const stattype INTGROWTH = (stattype)2;

	Wizard() : hp(BASEHP, BASEHP),
		Statblock(BASESTR, BASEINT)
	{}


private:
	// Унаследовано через LevelSystem
	void LevelUP() override {
		setMaxHP(HPGROWTH + getMaxHP());
		increaseStats(STRGROWTH, INTGROWTH);
	}
};