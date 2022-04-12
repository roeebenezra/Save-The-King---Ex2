#pragma once
#include <conio.h>
#include <cstdlib> // for std::system()

#include "Board.h"
#include "Utilities.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


class  Controller {
public:
	Controller(); //controller constructor

	int gamePlay();
	int loadLevels();
	void initLevelStats();
	void setMember();
	void updateStats(char);
	void updateKeyStatus(bool);
	void handleSpecialKey();
	void switchBetweenFigures();
	void manageFigures(const int, const int);

	char getFigure() const { return m_figure; }
	int getSteps() const { return m_steps; }
	int getLevel() const { return m_level; }
	bool getKeyStatus() const { return m_key; }

	//characters movment functions 
	void kingMov(const int, const int);
	void mageMov(const int, const int);
	void warriorMov(const int, const int);
	void thiefMov(const int, const int);

private:
	char m_figure;	
	int m_steps;	//sum up player steps
	int m_level;	//level number
	bool m_key;		//Thief key yes/no
	
	Board m_map;		//board member
	King m_king;		//caracters members
	Mage m_mage;
	Warrior m_warrior;
	Thief m_thief;
};



