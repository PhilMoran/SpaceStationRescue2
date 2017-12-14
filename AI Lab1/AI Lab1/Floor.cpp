#include "Floor.h"

Floor::Floor()
{
}

Floor::Floor(sf::Vector2f position)
{
	m_FloorPosition = position;
	m_FloorSource = IntRect(0, 0, 150, 150);
	m_FloorSprite.setTextureRect(m_FloorSource);
	m_FloorSprite.setPosition(m_FloorPosition);

	if (!m_FloorTexture.loadFromFile("ASSETS\\IMAGES\\tempFloor.png"))
	{
			// error...
	}

}

Floor::~Floor()
{
}
void Floor::Load(Texture& _FloorTexture)
{
	m_FloorSprite.setTexture(m_FloorTexture);
}

void Floor::draw(RenderWindow& _window)
{
	Load(m_FloorTexture);
	_window.draw(m_FloorSprite);
}