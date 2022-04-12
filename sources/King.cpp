#include "King.h"


King::King(const Location pos)	//constructor
	:m_kingPos(pos.m_row,pos.m_col), m_special(false),
					m_key(false), m_kingPrevPos(0, 0)
{}

//-------------------------------------------------------------------
void King::UpdateLocation(const Location& Location)
{
	m_kingPos = Location;
}
//-------------------------------------------------------------------
void King::setSpecialMov() 
{
	m_special.m_specialMov = true;
}
//-------------------------------------------------------------------
bool King::setNextMove(Board& map, const int row, const int col) 
{
	char cuur_tile = map.getTileByPress(this->getLocation(), row, col);

	if (this->valid_move(cuur_tile)) 
	{
		if (cuur_tile == TELEPORT) 
		{
			this->TeleportKing(map, row, col);
			return true;
		}
		if (m_key)
		{
			this->TileIsKEY(map);
			this->MoveTheKing(map, row, col);
			return true;
		}

		map.setNewMove(this->getLocation(), TILE);
		this->MoveTheKing(map, row, col);
		
		if (cuur_tile == KEY)
		{
			m_kingPrevPos = this->getLocation();
			m_key = true;
		}
		return true;

	}
	return false;
}
//-------------------------------------------------------------------
void King::TeleportKing(Board& map, const int row, const int col)
{
	this->UpdateLocation(map.MoveIntoTelport(this->getLocation(),
		row, col, KING));
}
//-------------------------------------------------------------------
void King::MoveTheKing(Board& map, const int row, const int col)
{
	this->UpdateLocation(Location(this->getLocation().m_row + row, 
								  this->getLocation().m_col + col));
	map.setNewMove(this->getLocation(), KING);
}

//-------------------------------------------------------------------
bool King::valid_move(const char tile) 
{
	if (tile == THRONE)
	{
		this->setSpecialMov();
		return true;
	}
	if (BoundaryVerif(tile) && (tile == KEY || tile == TILE ||
		tile == TELEPORT))
		return true;

	return false;
}
//------------------------------------------------------------------- 
void King::TileIsKEY(Board& map) 
{
	map.setNewMove(m_kingPrevPos, KEY);
	m_key = false;
}

