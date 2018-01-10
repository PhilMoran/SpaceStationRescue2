#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
#include <math.h>
#include "Worker.h"
using namespace std;

class Sweeper
{
public:
	Sweeper();
	Sweeper(sf::Vector2f position);
	~Sweeper();
	void Draw(sf::RenderWindow &window);
	void Load(); //Loads all external assets
	void Wander();
	void Flee();
	void Seek(Sprite & Player);
	float RadsToDegrees(float rads);
	float rand_FloatRange(float a, float b);
	Vector2f normalize(Vector2f & source);
	void CollectWorker(Worker* Worker);
private:
	sf::Vector2f sweepPos;
	Sprite sweepSprite;
	Texture sweepFullTex;
	Texture sweepEmptyTex;
	Texture sweepOnBoardTex;
	sf::Vector2f sweepVelocity;
	sf::Vector2f wanderPos;
	sf::Clock clock; // starts the clock
	bool alive = true;

};