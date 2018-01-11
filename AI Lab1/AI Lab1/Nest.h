#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
#include <math.h>
using namespace std;

class Nest
{
public:
	Nest();
	Nest(sf::Vector2f position);
	~Nest();

	void Draw(sf::RenderWindow &window);
	void Load(Texture&); //Loads all external assets

	void Seek(sf::Vector2f &pos);
	void Update(sf::Sprite &playerSprite);
	void Finder(int x, int y);
	void Fire(int x, int y);

	float maxSpeed;
	float currentOrientation;
	float missileLife;

private:
	sf::Sprite m_nestSprite;
	sf::Texture m_nestTexture;
	sf::Vector2f nestPos;

	sf::Sprite m_missileSprite;
	sf::Texture m_missileTexture;
	sf::Vector2f missilePos;
	sf::Vector2f missileVelocity;

	bool playerInRange;
	bool fireMissile;

	sf::Vector2f value;

	float getNewOrientation();
	sf::Vector2f Normalise(sf::Vector2f &vel);
};


