#pragma once
#include "Board.h"

class Mage {
public:
	Mage() = default;
	Mage(const Location);

	bool setNextMove(Board&, const int, const int);
	void moveTheMage(Board&, const int, const int);
	void setOldKey(Board&);
	void UpdateLocation(const Location&);

	Location getLocation()const { return m_magePos; }

	bool valid_move(const char)const;

private:
	Location m_magePos;     //cuurent position 
	Location m_magePrevPos; //previous position 
	bool m_key;				//mage can pass bay a key
};

