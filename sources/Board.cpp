#include "Board.h"


//-------------------------------------------------------------------
Board::Board() : m_file("levels.txt")	//constructor
{}

//-------------------------------------------------------------------
//find all caracters and tires on the board 
Location Board::setInitialPos(char figure) const 
{
	return locateCharacters(figure);
}
//-------------------------------------------------------------------
//to find weach move pressed
void Board::setNewMove(Location place, char figure) 
{
	m_board[place.m_row][place.m_col] = figure;
}

//---------------------------------------------------------------------------
//put the varibles into the object after find the telepots on the board
void Board::InitTelport() 
{
	m_teleport = this->teleportCount();
	m_teleArr = new Location[m_teleport];
	this->SetTeleport(m_teleArr, m_teleport);
}

//-------------------------------------------------------------------
//search teleports locations on loaded board
void Board::SetTeleport(Location* teleArr, int size) 
{
	int teleport_index = 0;

	for (int i = 0; i < m_board.size(); i++) {
		for (int j = 0; j < m_board[i].size(); j++)
		{
			if (TELEPORT == m_board[i][j]) {
				teleArr[teleport_index] = Location(i, j);
				teleport_index++;
			}
		}
	}
}
//-------------------------------------------------------------------
//caracter move into teleport handle function
Location Board::MoveIntoTelport(const Location curr_loc, const int row,
	const int col, const char figure) 
{
	Location afterTelport(curr_loc.m_row + row, curr_loc.m_col + col);
	afterTelport = this->GetTeleport(afterTelport);

	if (this->getTileByPress(afterTelport, 0, 1) == TILE)
	{
		this->setNewMove(curr_loc, TILE);
		afterTelport = (Location(afterTelport.m_row, afterTelport.m_col + 1));
		this->setNewMove(afterTelport, figure);
		return afterTelport;
	}
	return curr_loc;
}
//-------------------------------------------------------------------
//mange the number of teleport that found on the board
Location Board::GetTeleport(Location curr) 
{
	for (int i = 0; i < m_teleport; i++)
	{
		if (m_teleArr[i].m_col == curr.m_col && m_teleArr[i].m_row == curr.m_row)
		{
			if (i % 2 == 0)
				return m_teleArr[i + 1];
			else
				return m_teleArr[i - 1];
		}
	}
	return Location(-1, -1);
}

//-------------------------------------------------------------------
//count number of teleports on the board
int Board::teleportCount() 
{
	int teleCount = 0;

	for (int i = 0; i < m_board.size(); i++) {
		for (int j = 0; j < m_board[i].size(); j++)
		{
			if (TELEPORT == m_board[i][j])
				teleCount++;
		}
	}
	return teleCount;
}

//-------------------------------------------------------------------
//new level load from levels file
bool Board::SetNewLevel() 
{
	m_board.clear(); //delete the board game
	if (m_file.eof()) return (m_file.eof());

	for (auto line = std::string(); std::getline(m_file, line)&&(line.compare("\0") != 0); ) 
	{
		m_board.push_back(line);
	}

	return false;
}
//-------------------------------------------------------------------
//locate all nececery caraters on the board
Location Board::locateCharacters(const char figure) const
{
	for (int i = 0; i < m_board.size(); i++) 
	{
		for (int j = 0; j < m_board[i].size(); j++)
		{
			if (figure == m_board[i][j])
				return Location(i, j);
		}
	}

	return Location(0, 0);
}
//-------------------------------------------------------------------
char Board::getTileByPress(Location curr, int x_factor, int y_factor) 
{
	int new_x = (curr.m_row) + x_factor,
	    new_y = (curr.m_col) + y_factor;

	return (m_board[new_x][new_y]);
}
//-------------------------------------------------------------------
void Board::clearScreen() const 
{
	std::system("cls");
}
//-------------------------------------------------------------------
//finish level function
void Board::gameOver() const
{
	this->clearScreen();
	
	std::cout << "you win!" << std::endl << std::endl;
	std::cout << "Press ENTER to continue..." << std::endl;

	char c = getchar();
}
//-----------------------------------------------------------------------------
void Board::printBoard(const char figure, const int step,const bool hold_key,
	const int level)
{
	this->clearScreen();
	std::cout << "Level Number: " << level << std::endl;
	std::cout << "Control Character: " << figure << std::endl;
	std::cout << "Sum of Steps: " << step << std::endl;
	std::cout << "Thief have a Key: " << (hold_key ? "Yes" : "No") << std::endl;

	for (int i = 0; i < m_board.size(); i++) 
	{
		{
			std::cout << m_board[i];
			std::cout << std::endl;
		}
	}
}

