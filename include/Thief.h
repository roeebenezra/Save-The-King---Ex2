#pragma once
#include "Board.h"


class Thief {
public:
	Thief() = default;
	Thief(const Location first_pos);

	bool setNextMove(Board&, const int, const int);
	void moveTheif(Board&, const int, const int);
	void teleportMove(Board&, const int, const int);
	void setSpecialMove(bool);

	bool getSpecialMove() const { return m_special.m_specialMov; }
	Location getLocation()const { return m_ThiefPosition; }

	bool validMove(const char);
	void UpdateLocation(const Location&);

private:
	Location m_ThiefPosition;   // cuurent position 
	Special m_special;          // open gate % hold keys
};

