#pragma once
#include "Board.h"

class Warrior {
public:
	Warrior() = default;
	Warrior(const Location);

	bool setNextMov(Board&, const int, const int);
	void moveWarrior(Board&, const int, const int);
	void teleportWarrior(Board&, const int, const int);

	Location getLocation()const { return m_warPos; }

	bool validMove(const char);
	void tileKEY(Board&);
	void updateLocation(const Location&);

private:
	Location m_warPos;			//cuurent position 
	Location m_warPrevPos;		//previous position 
	bool m_Key;			        //warrior made key from ork
};

