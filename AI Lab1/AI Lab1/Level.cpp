#include "Level.h"


Level::Level()
{
	SetMap();
}


Level::~Level()
{
}

void Level::SetMap()
{
	maxCol = 26;
	maxRow = 15;
	pMap = (int*)map;
	CreateMap();
}
void Level::Draw(sf::RenderWindow *window)
{
	for (int index = 0; index < floorVector.size(); index++)
	{
		floorVector.at(index)->draw(*window);
	}

	for (int index = 0; index < wallVector.size(); index++)
	{
		wallVector.at(index)->draw(*window);
	}
}

void Level::CreateMap()
{
	// finds out the maximum amount of tiles on the map
	maxSquares = maxRow * maxCol;

	for (int column = 0; column < maxCol; column++)
	{
		for (int row = 0; row < maxRow; row++)
		{
			if (pMap[maxCol*(row)+column] == 1) // 1 is assigned the floor
			{
				floorVector.push_back(shared_ptr<Floor>(new Floor(sf::Vector2f(column * 150, row * 150))));

			}
			if (pMap[maxCol*(row)+column] == 2) // 2 is assigned the walls
			{
				wallVector.push_back(shared_ptr<Wall>(new Wall(sf::Vector2f(column * 150, row * 150))));

			}

		}
	}
}

const int Level::map[15][26]
{
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 }
};
