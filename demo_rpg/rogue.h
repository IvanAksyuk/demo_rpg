#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Rogue : public hp, public Statblock, public LevelSystem {

public:
	static const hptype BASEHP = (hptype)12;
	static const stattype BASESTR = (stattype)3;
	static const stattype BASEINT = (stattype)2;

	static const hptype HPGROWTH = (hptype)6;
	static const stattype STRGROWTH = (stattype)2;
	static const stattype INTGROWTH = (stattype)1;

	Rogue() : hp(BASEHP, BASEHP),
		Statblock(BASESTR, BASEINT)
	{}


private:
	// Унаследовано через LevelSystem
	void LevelUP() override {
		setMaxHP(HPGROWTH + getMaxHP());
		increaseStats(STRGROWTH, INTGROWTH);
	}

};