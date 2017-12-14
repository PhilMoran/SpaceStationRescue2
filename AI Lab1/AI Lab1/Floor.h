#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;

class Floor
{
public:
	Floor();
	Floor(sf::Vector2f position);
	~Floor();

	void draw(sf::RenderWindow &window);
	void Load(Texture&); //Loads all external assets


private:
	sf::Sprite m_FloorSprite;
	sf::Texture m_FloorTexture;

	IntRect m_FloorSource;
	Vector2f m_FloorPosition;
};

