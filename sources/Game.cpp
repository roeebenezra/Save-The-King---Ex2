#include "Game.h"

//Game constructor
//-------------------------------------------------------------------
Controller::Controller() :
	m_figure(KING), m_steps(0), m_key(false), m_level(0)
{}

//-------------------------------------------------------------------
void Controller::initLevelStats() 
{
	m_figure = KING;
	m_steps = 0;
	this->updateKeyStatus(false);
}
//-------------------------------------------------------------------
void Controller::setMember()
{
	m_king = (m_map.setInitialPos(KING));
	m_mage = (m_map.setInitialPos(MAGE));
	m_warrior = (m_map.setInitialPos(WARRIOR));
	m_thief = (m_map.setInitialPos(THIEF));
}
//-------------------------------------------------------------------
void Controller::updateStats(char c)
{
	m_steps++;
	m_figure = c;
}
//-------------------------------------------------------------------
void Controller::updateKeyStatus(bool hold)
{
	m_key = hold;
}

//game managment functions
//-----------------------------------------------------------------------------
int Controller::gamePlay() 
{
	setMember();
	m_map.printBoard(this->getFigure(), 
					 this->getSteps(),this->getKeyStatus(), this->getLevel());
	m_map.InitTelport();

	for (auto exit = false; !exit; ) {
		auto c = _getch();
		switch (c) {
		case 0:
		case SpecialKey:
			handleSpecialKey();
			break;
		case Change_Player:
			switchBetweenFigures();
			break;
		case Change_Player_Caps_lock:
			switchBetweenFigures();
			break;
		case KB_Escape:
			m_map.clearScreen();
			std::cout << std::endl << " **You Exited The Game**" << std::endl << std::endl;
			exit = true;
			return (EXIT_SUCCESS);
			break;
		default:
			std::cout << "Unknown key pressed (code = " << c << ")\n";
			break;
		}
		if (m_king.getSpecialMov()) {
			exit = true;
			m_map.gameOver();
		}
	}
	return (1);
}
//-------------------------------------------------------------------
void  Controller::handleSpecialKey()
{
	auto c = _getch();
	switch (c) {
	case KB_Up:
		manageFigures(UP, 0);
		break;
	case KB_Down:
		manageFigures(DOWN, 0);
		break;
	case KB_Left:
		manageFigures(0, LEFT);
		break;
	case KB_Right:
		manageFigures(0, RIGHT);
		break;
	default:
		break;
	}
}
//-------------------------------------------------------------------
void Controller::manageFigures(const int row, const int col)
{
	switch (m_figure)
	{
	case KING:
		this->kingMov(row, col);
		break;
	case MAGE:
		this->mageMov(row, col);
		break;
	case WARRIOR:
		this->warriorMov(row, col);
		break;
	case THIEF:
		this->thiefMov(row, col);
		break;
	default:
		break;
	}

	m_map.printBoard(this->getFigure(), this->getSteps(),
		this->getKeyStatus(), this->getLevel());
}
//-------------------------------------------------------------------
void Controller::switchBetweenFigures() 
{
	switch (m_figure)
	{
	case KING:
		m_figure = MAGE;
		break;
	case MAGE:
		m_figure = WARRIOR;
		break;
	case WARRIOR:
		m_figure = THIEF;
		break;
	case THIEF:
		m_figure = KING;
		break;
	default:
		break;
	}
	m_map.printBoard(this->getFigure(), this->getSteps(),
		this->getKeyStatus(), this->getLevel());
}
//-------------------------------------------------------------------
int Controller::loadLevels() 
{
	for (m_level = 1; !(m_map.SetNewLevel()); m_level++) 
	{
		if (this->gamePlay() > 0) 
			this->initLevelStats();
		else
			break;
	}
	return (EXIT_SUCCESS);
}

//characters movment functions
//-------------------------------------------------------------------
void Controller::kingMov(const int row, const int col) 
{
	if (m_king.setNextMove(m_map, row, col))
		this->updateStats(this->getFigure());
}
//-------------------------------------------------------------------
void Controller::mageMov(const int row, const int col) 
{
	if (m_mage.setNextMove(m_map, row, col))
		this->updateStats(this->getFigure());
}
//-------------------------------------------------------------------
void Controller::warriorMov(const int row, const int col)
{
	if (m_warrior.setNextMov(m_map, row, col))
		this->updateStats(this->getFigure());
}
//-------------------------------------------------------------------
void Controller::thiefMov(const int row, const int col) 
{
	if (m_thief.setNextMove(m_map, row, col)) {
		this->updateKeyStatus(m_thief.getSpecialMove());
		this->updateStats(this->getFigure());
	}
}

