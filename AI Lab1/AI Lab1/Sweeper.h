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
	void Seek(Worker* Worker);
	float RadsToDegrees(float rads);
	float rand_FloatRange(float a, float b);
	float Distance(float x1, float y1, float x2, float y2);
	Vector2f normalize(Vector2f & source);
	void CollectWorker(Worker* Worker);
	Sprite sweepSprite;
	bool sweepingArea = false;
	bool empty = true;
	void Flee(Sprite Player);
private:
	sf::Vector2f sweepPos;
	
	Texture sweepFullTex;
	Texture sweepEmptyTex;
	Texture sweepOnBoardTex;
	sf::Vector2f sweepVelocity;
	sf::Vector2f wanderPos;
	sf::Clock clock; // starts the clock
	bool alive = true;


};