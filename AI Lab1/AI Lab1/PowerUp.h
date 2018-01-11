#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
#include <math.h>
using namespace std;

class PowerUp
{
public:
	PowerUp();
	PowerUp(sf::Vector2f position);
	~PowerUp();

	void Draw(sf::RenderWindow &window);
	void Load(Texture&); //Loads all external assets
	void Update(sf::Sprite &playerSprite);

	bool radar;

private:
	sf::Sprite m_powerUpSprite;
	sf::Texture m_powerUpTexture;
	sf::Vector2f powerUpPos;

	bool powerUpAlive;
	float timer;
};

