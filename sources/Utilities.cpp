#include "Utilities.h"

bool BoundaryVerif(const char tile)
{
	if (tile == WALL || tile == '/')
		return (false);

	return (true);
}