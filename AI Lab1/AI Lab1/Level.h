#pragma once
#include <SFML/Graphics.hpp> 
#include <memory>

#include "Floor.h"
#include "Wall.h"

class Level
{
public:
	Level();
	~Level();
	int *pMap;
	void Draw(sf::RenderWindow *window);
	void CreateMap();
	void SetMap();


private:
	int maxRow;
	int maxCol;
	int maxSquares;

	//int	row = 

	static const int map[15][26];

	std::vector<shared_ptr<Floor>> floorVector;
	std::vector<shared_ptr<Wall>> wallVector;
};

