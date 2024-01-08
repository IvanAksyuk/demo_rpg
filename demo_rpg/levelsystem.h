#pragma once

#include <cstdint>
typedef std::uint64_t exptype;
typedef std::uint16_t level_type;

class LevelSystem {
public:
	LevelSystem() : CurrentLevel(1), CurrentEXP(0) {}

	void gainEXP(exptype gained_exp) {
		CurrentEXP += gained_exp;
		check_if_leveled();
	}
protected:
	level_type CurrentLevel;
	exptype CurrentEXP;
	level_type LevelUpsAvailable;

	void check_if_leveled() {

	}
};