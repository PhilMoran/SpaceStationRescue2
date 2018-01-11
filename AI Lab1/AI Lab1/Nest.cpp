#include "Nest.h"
using namespace sf;
#include <iostream>


Nest::Nest()
{
}

Nest::Nest(sf::Vector2f position)
{
	nestPos = position;
	m_nestSprite.setPosition(nestPos);
	m_nestSprite.setOrigin(m_nestSprite.getGlobalBounds().width / 2, m_nestSprite.getGlobalBounds().height / 2);

	if (!m_nestTexture.loadFromFile("ASSETS\\IMAGES\\Nest.png"))
	{
		// error...
	}

	missilePos = position;
	m_missileSprite.setPosition(missilePos);

	if (!m_missileTexture.loadFromFile("ASSETS\\IMAGES\\missile.png"))
	{
		// error...
	}

	missileVelocity = sf::Vector2f(1.0f, 1.0f);
	playerInRange = false;
	fireMissile = false; //Checks if the missile is alive
	maxSpeed = 0.4f; //How fast the missile will move
	currentOrientation = 0.0f;
	missileLife = 2500; //How long the missile will live for (should it not hit the player)
}


Nest::~Nest()
{
}

// A method for finding if the player is in range of the nest
void Nest::Finder(int x, int y)
{
	sf::Vector2f playerPos(x, y);
	sf::Vector2f total = nestPos - playerPos;

	float totalDiff = sqrt(pow(total.x, 2) + pow(total.y, 2));
	int checkDistance = 400; //The range in which the nest looks for the player

	if (totalDiff <= checkDistance)
	{
		playerInRange = true;
	}
	else
	{
		playerInRange = false;
	}
}

// Fires the missile at the player
void Nest::Fire(int x, int y)
{
	sf::Vector2f playerPos(x, y);
	sf::Vector2f total = nestPos - playerPos;

	if (playerInRange == true)
	{
		cout << "INRANGE" << endl;
		fireMissile = true;
	}
}
 
void Nest::Seek(sf::Vector2f &pos)
{
	missileVelocity = pos - missilePos;
	missileVelocity = Normalise(missileVelocity);
	missileVelocity = missileVelocity * maxSpeed;
	float orientation = getNewOrientation();
	m_missileSprite.setRotation(orientation * (180 / 3.14159));
}

void Nest::Update(sf::Sprite &playerSprite)
{
	Finder(playerSprite.getPosition().x, playerSprite.getPosition().y);
	Fire(playerSprite.getPosition().x, playerSprite.getPosition().y);
	cout << missileLife << endl;
	if (!playerInRange && missileLife <= 0)
	{
		missileLife = 2500;
	}

	if (fireMissile == true)
	{
		cout << "Missile Alive" << endl;
		// 'value' gives the missile a destination to reach(i.e. the players position)
		value = playerSprite.getPosition();
		if (missileLife > 0)
		{
			Seek(value);
		}

		missileLife--;
		missilePos += missileVelocity;
		m_missileSprite.setPosition(missilePos);
	}
	if(missileLife <= 0)
	{
		fireMissile = false;
		missileLife = 0;
		missilePos.x = nestPos.x;
		missilePos.y = nestPos.y + 75;
	}
	// If the player and missile collide with one another
	if (playerSprite.getGlobalBounds().intersects(m_missileSprite.getGlobalBounds()))
	{
		fireMissile = false;
		missileLife = 0;
	}
}

void Nest::Load(Texture& _FloorTexture)
{
	m_nestSprite.setTexture(m_nestTexture);
	m_missileSprite.setTexture(m_missileTexture);
}

void Nest::Draw(RenderWindow& _window)
{
	Load(m_nestTexture);
	_window.draw(m_nestSprite);

	if (fireMissile == true)
	{
		Load(m_missileTexture);
		_window.draw(m_missileSprite);
	}
}

float Nest::getNewOrientation()
{
	float square = (missileVelocity.x * missileVelocity.x) + (missileVelocity.y * missileVelocity.y);
	float length = sqrt(square);
	if (length > 0)
	{
		return atan2(missileVelocity.x, -missileVelocity.y);
	}
	else
	{
		return currentOrientation;
	}
}

sf::Vector2f Nest::Normalise(sf::Vector2f &aVel)
{
	float square = (aVel.x * aVel.x) + (aVel.y * aVel.y);
	float length = sqrt(square);
	sf::Vector2f result = (aVel.x / length, aVel / length);
	return result;
}
