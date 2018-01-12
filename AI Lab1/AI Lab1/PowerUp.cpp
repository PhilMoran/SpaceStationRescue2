#include "PowerUp.h"


PowerUp::PowerUp()
{
}

PowerUp::PowerUp(sf::Vector2f position)
{
	powerUpPos = position;
	m_powerUpSprite.setPosition(powerUpPos);
	m_powerUpSprite.setScale(0.25, 0.25);

	if (!m_powerUpTexture.loadFromFile("ASSETS\\IMAGES\\Radar.png"))
	{
		// error...
	}

	powerUpAlive = true;
	radar = false;
	timer = 3000;
}


PowerUp::~PowerUp()
{
}

void PowerUp::Update(sf::Sprite &playerSprite)
{
	if (powerUpAlive == true)
	{
		if (playerSprite.getGlobalBounds().intersects(m_powerUpSprite.getGlobalBounds()))
		{
			cout << "HITTING POWER-UP" << endl;
			powerUpAlive = false;

			radar = true;

		}
	}
	if (radar == true)
	{
		timer--;
		if (timer <= 0)
		{
			radar = false;
		}

	}
}

void PowerUp::Load(Texture& _healthTexture)
{
	m_powerUpSprite.setTexture(m_powerUpTexture);
	m_powerUpSprite.setTexture(m_powerUpTexture);
}

void PowerUp::Draw(RenderWindow& _window)
{
	if (powerUpAlive == true)
	{
		Load(m_powerUpTexture);
		_window.draw(m_powerUpSprite);
	}
}