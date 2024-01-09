#pragma once
#include <string>
#include <cstdint>

enum class ABILITYTARGET{SELF, ALLY, ENEMY};
enum class ABILITYSCALER { NONE, STR, AGI, INT };
struct Ability {
	Ability(std::string n, uint32_t cost, uint32_t cd, ABILITYTARGET t, uint32_t hpe, ABILITYSCALER as):
		Name(n), 
		Cost(cost),
		Cooldown(cd),
		Target(t), 
		HP_effect(hpe),
		AbilityScaler(as)
	{}
	std::string Name="unnamed";
	uint32_t Cost = 0; //assume mp if there is a cost
	uint32_t Cooldown = 1; // number of rounds you have to wait before using it again
	ABILITYTARGET Target = ABILITYTARGET::SELF;
	uint32_t HP_effect = 1;
	ABILITYSCALER AbilityScaler = ABILITYSCALER::NONE;

};