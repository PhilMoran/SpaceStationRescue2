#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(sf::Vector2f position)
{
	m_WallPosition = position;
	m_WallSource = IntRect(0, 0, 150, 150);
	m_WallSprite.setTextureRect(m_WallSource);
	m_WallSprite.setPosition(m_WallPosition);

	if (!m_WallTexture.loadFromFile("ASSETS\\IMAGES\\tempWall.png"))
	{
		// error...
	}
}

Wall::~Wall()
{
}

void Wall::Load(Texture& _WallTexture)
{
	m_WallSprite.setTexture(m_WallTexture);
}

void Wall::draw(RenderWindow& _window)
{
	Load(m_WallTexture);
	_window.draw(m_WallSprite);
}