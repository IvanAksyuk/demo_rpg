#pragma once

#include <cstdint>
typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class LevelSystem {
public:
	static const exptype LEVEL2AT = 100;
	LevelSystem(): 
		CurrentLevel(1), 
		CurrentEXP(0), 
		EXPToNextLevel(LEVEL2AT)
	{}

	void gainEXP(exptype gained_exp) {
		CurrentEXP += gained_exp;
		while (check_if_leveled()) {}

	}
	leveltype getLevel() {
		return CurrentLevel;
	}
	exptype getCurrentEXP() {
		return CurrentEXP;
	}
	exptype getEXPToNextLevel() {
		return EXPToNextLevel;
	}
	virtual void LevelUP() = 0;



protected:
	leveltype CurrentLevel;
	exptype CurrentEXP;
	exptype EXPToNextLevel;

	bool check_if_leveled() {
		
		static const leveltype LEVELSCALAR = 2;
		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			LevelUP();
			EXPToNextLevel *= LEVELSCALAR;
			return true;
		}
		return false;
		
	}
};