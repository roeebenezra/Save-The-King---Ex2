#include "Warrior.h"

Warrior::Warrior(const Location firstPos)
	:m_warPos(firstPos.m_row, firstPos.m_col),m_warPrevPos(0,0),m_Key(false)
{}

//-----------------------------------------------------------------------------
void Warrior::updateLocation(const Location& loc) 
{
	m_warPos = loc;
}

//-----------------------------------------------------------------------------
void Warrior::moveWarrior(Board& map, const int row, const int col)
{
	this->updateLocation(Location(this->getLocation().m_row + row,
							      this->getLocation().m_col + col));
	map.setNewMove(this->getLocation(), WARRIOR);
}


//-----------------------------------------------------------------------------
//warrior next move func
bool Warrior::setNextMov(Board& map, const int row, const int col) \
{
	char cuur_tile = map.getTileByPress(this->getLocation(), row, col);

	if (this->validMove(cuur_tile))
	{
		if (cuur_tile == TELEPORT) 
		{
			this->teleportWarrior(map, row, col);
			return true;
		}

		if (m_Key) 
		{
			this->tileKEY(map);
			this->moveWarrior(map, row, col);
			return true;
		}

		map.setNewMove(this->getLocation(), TILE);
		this->moveWarrior(map, row, col);
		
		if (cuur_tile == KEY || cuur_tile == ORK)
		{
			m_warPrevPos= this->getLocation();
			m_Key = true;
		}
		return true;
	}

	return false;
}
//-----------------------------------------------------------------------------
void Warrior::teleportWarrior(Board& map, const int row, const int col)
{
	this->updateLocation(map.MoveIntoTelport(this->getLocation(),
		row, col, WARRIOR));
}

//vaild move check of warrior
//-----------------------------------------------------------------------------
bool Warrior::validMove(const char tile) 
{
	if (BoundaryVerif(tile) && (tile == KEY || tile == ORK ||
							tile == TILE || tile == TELEPORT))
		return true;
	
	return false;
}

//----------------------------------------------------------------------------- 
void Warrior::tileKEY(Board& map)
{
	map.setNewMove(m_warPrevPos, KEY);
	m_Key = false;
}

