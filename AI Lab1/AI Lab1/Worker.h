#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
#include <iostream>
#include <math.h>
using namespace std;

class Worker
{
public:
	Worker();
	Worker(sf::Vector2f position);
	~Worker();

	void Draw(sf::RenderWindow &window);
	void Load(); //Loads all external assets
	void Wander();
	void Collected(Sprite & Player);
	void Update();
	void Seek();
	bool alive = true;
	float rand_FloatRange(float a,float b);
	float RadsToDegrees(float rads);
	sf::Vector2f normalize(sf::Vector2f & source);
	sf::Sprite m_workerSprite;

private:
	
	sf::Texture m_workerTexture;
	sf::Vector2f workerPos;
	sf::Vector2f wanderPos;
	
	int collected = 0;
	
	char temp[256];
	
	sf::Clock clock; // starts the clock
	Vector2f WanderPos = Vector2f(400, 200);
	int deltaangle;
	int nextangle;

};