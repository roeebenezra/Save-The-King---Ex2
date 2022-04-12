#include "Mage.h"


Mage::Mage(const Location pos)	//constructor
	:m_magePos(pos.m_row,pos.m_col),m_magePrevPos(0, 0), m_key(false)
{}

//-------------------------------------------------------------------
bool Mage::setNextMove(Board& map, const int row, const int col)
{
	char cuur_tile = map.getTileByPress(this->getLocation(), row, col);

	if (this->valid_move(cuur_tile)) {
		if (m_key) {
			this->setOldKey(map);
			this->moveTheMage(map, row, col);
			return true;
		}
		map.setNewMove(this->getLocation(), TILE);
		this->moveTheMage(map, row, col);
		if (cuur_tile == KEY) {
			m_magePrevPos = this->getLocation();
			m_key = true;
		}
		return (true);
	}
	return (false);
}
//------------------------------------------------------------------- 
void Mage::UpdateLocation(const Location& loc)
{
	m_magePos = loc;
}
//------------------------------------------------------------------- 
void Mage::setOldKey(Board& map) 
{
	map.setNewMove(m_magePrevPos, KEY);
	m_key = false;
}
//-------------------------------------------------------------------
void Mage::moveTheMage(Board& map, const int row,const int col)
{
	this->UpdateLocation(Location(this->getLocation().m_row + row,
		this->getLocation().m_col + col));
	map.setNewMove(this->getLocation(), MAGE);
}
//check functions
//-------------------------------------------------------------------
bool Mage::valid_move(const char tile) const
{
	if (BoundaryVerif(tile) && (tile == KEY || tile == FIRE || tile == TILE))
		return true;

	return false;
}