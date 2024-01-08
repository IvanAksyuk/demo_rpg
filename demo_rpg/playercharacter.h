#pragma once

#include <cstdint>

#include "statblock.h"
#include "pointwell.h"
#include <memory>

typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;



class PlayerCharacterDelegate: public Statblock {
public:
	static const exptype LEVEL2AT = 100;
	PlayerCharacterDelegate() :
		Statblock(0,0),
		CurrentLevel(1),
		CurrentEXP(0),
		EXPToNextLevel(LEVEL2AT)
	{
		HP = std::make_unique<PointWell>();
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
#define PCCONSTRUCT : PlayerCharacterDelegate() {\
HP->setMax(BASEHP);\
HP->increase(BASEHP);\
increaseStats(BASESTR, BASEINT);\
}

#define LEVELUP void LevelUP() override {\
HP->setMax((welltype)(BASEHP / 2.f) + HP->getMax());\
HP->increase(HP->getMax());\
increaseStats((stattype)((BASESTR + 1) / 2.f), (stattype)((BASEINT + 1) / 2.f));\
}


class Cleric : public PlayerCharacterDelegate {

public:
	static const welltype BASEHP = (welltype)14;
	static const stattype BASESTR = (stattype)2;
	static const stattype BASEINT = (stattype)3;

	std::string getClassName() override { return std::string("Cleric"); }
	Cleric() PCCONSTRUCT

	

private:
	
	LEVELUP
	
};

class Rogue : public PlayerCharacterDelegate {

public:
	static const welltype BASEHP = (welltype)12;
	static const stattype BASESTR = (stattype)3;
	static const stattype BASEINT = (stattype)2;

	std::string getClassName() override { return std::string("Rogue"); }
	Rogue() PCCONSTRUCT

	

private:

	LEVELUP
};

class Warrior : public PlayerCharacterDelegate {

public:
	static const welltype BASEHP = (welltype)18;
	static const stattype BASESTR = (stattype)4;
	static const stattype BASEINT = (stattype)1;

	std::string getClassName() override { return std::string("Warrior"); }
	Warrior() PCCONSTRUCT



private:

	LEVELUP
};

class Wizard : public PlayerCharacterDelegate {

public:
	static const welltype BASEHP = (welltype)10;
	static const stattype BASESTR = (stattype)1;
	static const stattype BASEINT = (stattype)4;

	std::string getClassName() override { return std::string("Wizard"); }

	Wizard() PCCONSTRUCT

	
private:

	LEVELUP
};



class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;

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
	stattype getStrength() { return pcclass->getStrength(); }
	stattype getIntellect() { return  pcclass->getIntellect(); }

	void gainEXP(exptype amt) {  pcclass->gainEXP(amt); }
	void takeDamage(welltype amt) {  pcclass->HP->reduce(amt); }
	void heal(welltype amt) {  pcclass->HP->increase(amt); }

};