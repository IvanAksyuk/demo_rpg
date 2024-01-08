#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Cleric : public hp, public Statblock, public LevelSystem {

public:
	static const hptype BASEHP = (hptype)14;
	static const stattype BASESTR = (stattype)2;
	static const stattype BASEINT = (stattype)3;

	static const hptype HPGROWTH = (hptype)7;
	static const stattype STRGROWTH = (stattype)1;
	static const stattype INTGROWTH = (stattype)2;

	Cleric() : hp(BASEHP, BASEHP),
		Statblock(BASESTR, BASEINT)
	{}



	
private:
	// Унаследовано через LevelSystem
	void LevelUP() override {
		setMaxHP(HPGROWTH + getMaxHP());
		increaseStats(STRGROWTH, INTGROWTH);
	}
};