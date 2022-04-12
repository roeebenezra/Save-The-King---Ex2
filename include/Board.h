#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Location.h"
#include "Utilities.h"

class Board
{
public:
	Board();

	void printBoard(const char , const int, const bool, const int );
	Location locateCharacters(const char) const;
	Location setInitialPos(char) const;
	
	Location MoveIntoTelport(const Location, const int, const int, const char);
	void InitTelport();
	int teleportCount();
	void SetTeleport(Location* , int);
	Location GetTeleport(Location);

	bool SetNewLevel();
	void setNewMove(Location, char);

	char getTileByPress(Location, int , int );
	void gameOver() const;
	void clearScreen() const;

private:
	int m_teleport;						//num of telepotrs
	std::vector<std::string> m_board;	//board vector
	Location* m_teleArr;				//teleports loc arr
	std::ifstream m_file;				//levels file
};
