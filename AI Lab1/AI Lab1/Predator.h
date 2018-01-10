#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
#include <math.h>
using namespace std;

class Predator
{
public:
	Predator();
	Predator(sf::Vector2f position);
	~Predator();
	void Draw(sf::RenderWindow &window);
	void Load(); //Loads all external assets
	void Seek(Sprite & Player);
	float RadsToDegrees(float rads);
	Vector2f normalize(Vector2f & source);
private:
	sf::Vector2f predPos;
	Sprite predSprite;
	Texture predTex;
	sf::Vector2f predVelocity;
	bool alive = true;

};