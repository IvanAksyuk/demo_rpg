#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Warrior : public hp, public Statblock, public LevelSystem {

public:
	static const hptype BASEHP = (hptype)18;
	static const stattype BASESTR = (stattype)4;
	static const stattype BASEINT = (stattype)1;

	static const hptype HPGROWTH = (hptype)9;
	static const stattype STRGROWTH = (stattype)2;
	static const stattype INTGROWTH = (stattype)1;

	Warrior() : hp(BASEHP, BASEHP),
		Statblock(BASESTR, BASEINT)
	{}

private:
	// Унаследовано через LevelSystem
	void LevelUP() override {
		setMaxHP(HPGROWTH + getMaxHP());
		increaseStats(STRGROWTH, INTGROWTH);
	}
};