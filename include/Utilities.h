#pragma once
#include "Location.h"

bool BoundaryVerif(const char);

//characters & kes enums
enum Movment
{
	UP = -1,
	DOWN = 1,
	LEFT = -1,
	RIGHT = 1,
};

enum Keys
{
	KB_Escape = 27,
	SpecialKey = 224,
	Change_Player = 112,
	Change_Player_Caps_lock = 80,
};

enum SpecialKeys
{
	KB_Up = 72,
	KB_Down = 80,
	KB_Left = 75,
	KB_Right = 77,
};

enum gameBoard
{
    GATE = 35,
    FIRE = 42,
    ORK = 33,
    KEY = 70,
    TELEPORT = 88,
    WALL = 61,
    THRONE = 64,
    TILE = 32,
};
enum gameCharacters
{
    WARRIOR = 87,
    KING = 75,
    MAGE = 77,
    THIEF = 84,
};
