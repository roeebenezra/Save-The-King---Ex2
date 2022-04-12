#pragma once
#include "Board.h"

class King {
public:
	King() = default;
	King(const Location);

	bool setNextMove(Board&, const int, const int);
	void setSpecialMov();
	void UpdateLocation(const Location&);

	Location getLocation()const { return m_kingPos; }
	bool getSpecialMov()const{ return m_special.m_specialMov; }

	bool valid_move(const char);
	void TileIsKEY(Board&);

	void MoveTheKing(Board&, const int, const int);
	void TeleportKing(Board&, const int, const int);

private:
	Location m_kingPos;     //cuurent position 
	Location m_kingPrevPos; //previous position
	Special m_special;      //get to Throne
	bool m_key;	 		    //king can pass by key
};
