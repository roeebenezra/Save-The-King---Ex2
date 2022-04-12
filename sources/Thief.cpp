#include "Thief.h"


Thief::Thief(const Location pos)		//constructor
	:m_ThiefPosition(pos.m_row, pos.m_col)
{}

//set & update functions
//-------------------------------------------------------------------
bool Thief::setNextMove(Board& map, const int row, const int col)
{
	char cuur_tile = map.getTileByPress(this->getLocation(), row, col);

	if (this->validMove(cuur_tile)) 
	{
		if (cuur_tile == TELEPORT)
		{
			this->teleportMove(map, row, col);
			return true;
		}

		if (cuur_tile != GATE || (this->getSpecialMove()))
		{
			map.setNewMove(this->getLocation(), TILE);
			this->moveTheif(map, row, col);
			if (cuur_tile == GATE && (this->getSpecialMove()))
				this->setSpecialMove(false);
			return true;
		}
	}

	return false;
}
//-------------------------------------------------------------------
void Thief::UpdateLocation(const Location& Location) 
{
	m_ThiefPosition = Location;
}

//-------------------------------------------------------------------
void Thief::setSpecialMove(bool curr)
{
	m_special.m_specialMov = curr;
}
//-------------------------------------------------------------------
void Thief::moveTheif(Board& map, const int row, const int col)
{
	this->UpdateLocation(Location(this->getLocation().m_row + row,
								  this->getLocation().m_col + col));
	map.setNewMove(this->getLocation(), THIEF);
}
//------------------------------------------------------------------- 
void Thief::teleportMove(Board& map, const int row, const int col) 
{
	this->UpdateLocation(map.MoveIntoTelport(this->getLocation(),row, col, THIEF));
}

//valid move func
bool Thief::validMove(const char tile) {

	if (tile == KEY && !(this->getSpecialMove()))
	{
		this->setSpecialMove(true);
		return true;
	}
	if (BoundaryVerif(tile) && (tile == TILE || tile == GATE ||
		tile == TELEPORT))
		return true;

	return false;
}

