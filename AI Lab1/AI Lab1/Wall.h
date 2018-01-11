#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;



class Wall
{
public:
	Wall();
	Wall(sf::Vector2f position);
	~Wall();
	void draw(sf::RenderWindow &window);
	void Load(Texture&); //Loads all external assets

private:
	sf::Sprite m_WallSprite;
	sf::Texture m_WallTexture;

	IntRect m_WallSource;
	Vector2f m_WallPosition;

};

