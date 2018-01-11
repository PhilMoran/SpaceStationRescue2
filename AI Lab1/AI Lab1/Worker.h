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
	void Load(Texture&); //Loads all external assets
	void Wander(int wall);
	float rand_FloatRange(float a);

private:
	sf::Sprite m_workerSprite;
	sf::Texture m_workerTexture;
	sf::Vector2f workerPos;
	sf::Vector2f wanderPos;
	int deltaangle;
	int nextangle;

};