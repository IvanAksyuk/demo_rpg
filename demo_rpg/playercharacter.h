#pragma once

#include <cstdint>

#include "statblock.h"
#include "pointwell.h"
#include "ability.h"
#include <vector>
#include <memory>
typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;



class PlayerCharacterDelegate: public Statblock {
public:
	static const exptype LEVEL2AT = 100;
	PlayerCharacterDelegate() :
		Statblock(),
		CurrentLevel(1),
		CurrentEXP(0),
		EXPToNextLevel(LEVEL2AT)
	{
		HP = std::make_unique<PointWell>();
		//MP = std::make_unique<PointWell>();
	}

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
	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell> HP;
	std::unique_ptr<PointWell> MP;
	std::vector<Ability> Abilities;

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
#define PCCONSTRUCT \
HP->setMax(BASEHP); \
HP->increase(BASEHP);if(MP){\
MP->setMax(BASEMP);\
MP->increase(BASEMP); \
}\
increaseStats(BASESTR, BASEINT, BASEAGI);

#define LEVELUP \
HP->setMax((welltype)(BASEHP / 2.f) + HP->getMax());\
HP->increase(HP->getMax());\
if(MP){\
	MP->setMax((welltype)(BASEMP / 2.f) + MP->getMax()); \
	MP->increase(MP->getMax()); \
}\
increaseStats((stattype)((BASESTR + 1) / 2.f),\
(stattype)((BASEINT + 1) / 2.f),\
(stattype)((BASEAGI + 1) / 2.f));

//#define CHARACTERCLASS(classname, basehp, basestr, baseint,baseagi) \

class Cleric: public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)14;
	static const stattype BASESTR = (stattype)3;
	static const stattype BASEINT = (stattype)5;
	static const stattype BASEAGI = (stattype)1;
	static const welltype BASEMP = (welltype)10;
	std::string getClassName() override { return std::string("Cleric"); }

	Cleric() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>(BASEMP, BASEMP);
		PCCONSTRUCT
			
			
			Abilities.emplace_back(Ability("Heal", 2u, 1u, ABILITYTARGET::ALLY, 2u, ABILITYSCALER::INT));
	}
		

private:
	 void LevelUP() override 
	 { 
		 LEVELUP 
			 
			 if (CurrentLevel == 2) {
				 Abilities.emplace_back(Ability("Smite", 2u, 1u, ABILITYTARGET::ENEMY, 2u, ABILITYSCALER::INT));

		}
	 }

};


class Wizard : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)10;
	static const welltype BASEMP = (welltype)14;
	static const stattype BASESTR = (stattype)1;
	static const stattype BASEINT = (stattype)8;
	static const stattype BASEAGI = (stattype)2;
	
	std::string getClassName() override { return std::string("Wizard"); }

	Wizard() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>(BASEMP, BASEMP);
		PCCONSTRUCT


			Abilities.emplace_back(Ability("FireBolt", 2u, 1u, ABILITYTARGET::ENEMY, 4u, ABILITYSCALER::INT));
	}


private:
	void LevelUP() override
	{
		LEVELUP

			if (CurrentLevel == 2) {
				Abilities.emplace_back(Ability("IceBolt", 3u, 2u, ABILITYTARGET::ENEMY, 6u, ABILITYSCALER::INT));
				
				MP->setMax((welltype)(1) + MP->getMax()); 
				MP->increase(MP->getMax()); 

				increaseStats(0, 1, 0, 0, 0);
			}
		if (CurrentLevel == 3) {

			}
	}

};


class Warrior : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)18;
	static const welltype BASEMP = (welltype)0;
	static const stattype BASESTR = (stattype)6;
	static const stattype BASEINT = (stattype)2;
	static const stattype BASEAGI = (stattype)2;

	std::string getClassName() override { return std::string("Warrior"); }

	Warrior() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>(BASEMP, BASEMP);
		PCCONSTRUCT


				}


private:
	void LevelUP() override
	{
		LEVELUP

			if (CurrentLevel == 2) {
				Abilities.emplace_back(Ability("PowerAttack", 0u, 3u, ABILITYTARGET::ENEMY, 4u, ABILITYSCALER::STR));

				//Abilities.emplace_back(Ability("IceBolt", 3u, 2u, ABILITYTARGET::ENEMY, 6u, ABILITYSCALER::INT));

			
			}
		if (CurrentLevel == 3) {

		}
	}

};
//CHARACTERCLASS(Berserker, 22, 6, 1)







class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;
	//Inventory* inv;
	//Equipment..
public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate* pc): pcclass(pc){}
	~PlayerCharacter() { delete pcclass; pcclass = nullptr; }

	std::string getClassName() { return pcclass->getClassName(); }
	leveltype getLevel() { return pcclass->getLevel(); }
	exptype getCurrentEXP() { return pcclass->getCurrentEXP(); }
	exptype getEXPToNextLevel() { return pcclass->getEXPToNextLevel(); }
	welltype getCurrentHP() { return pcclass->HP->getCurrent(); }
	welltype getMaxHP() { return pcclass->HP->getMax(); }
	welltype getCurrentMP() { 
		if(pcclass->MP) return pcclass->MP->getCurrent(); 
		return 0;
	}
	
	welltype getMaxMP() {
		if (pcclass->MP) return pcclass->MP->getMax(); 
		return 0;
	}
	stattype getStrength() { return pcclass->getStrength(); }
	stattype getIntellect() { return  pcclass->getIntellect(); }
	stattype getAgility() { return pcclass->getAgility(); }
	stattype getArmor() { return  pcclass->getArmor(); }
	stattype getElementRes() { return  pcclass->getElementRes(); }

	std::vector<Ability> getAbilityList() { return pcclass->Abilities; }

	void gainEXP(exptype amt) {  pcclass->gainEXP(amt); }
	void takeDamage(welltype amt) {  pcclass->HP->reduce(amt); }
	void heal(welltype amt) {  pcclass->HP->increase(amt); }

};