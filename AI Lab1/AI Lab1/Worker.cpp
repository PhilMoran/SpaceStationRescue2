#include "Worker.h"

Worker::Worker()
{

}
Worker::Worker(sf::Vector2f position)
{
	workerPos = position;
	m_workerSprite.setPosition(workerPos);

	if (!m_workerTexture.loadFromFile("ASSETS\\IMAGES\\worker.png"))
	{
		// error...
	}
}

Worker::~Worker()
{
}
void Worker::Load(Texture& _FloorTexture)
{
	m_workerSprite.setTexture(m_workerTexture);
	m_workerSprite.setScale(0.2, 0.2);
}

void Worker::Draw(RenderWindow& _window)
{
	Load(m_workerTexture);
	_window.draw(m_workerSprite);
}
void Worker::Wander(int wall)
{
	Vector2f adjustment = Vector2f(0,0);
	if (m_workerSprite.getGlobalBounds().left < wall)
	{
		int distance = wall - m_workerSprite.getGlobalBounds().left;
		adjustment.x = distance;
	}
	else if (m_workerSprite.getGlobalBounds().width >(1080 - wall))
	{
		int distance = (1080 - wall) - m_workerSprite.getGlobalBounds().width;
		adjustment.x = distance;
	}
	if (m_workerSprite.getGlobalBounds().top < wall)
	{
		int distance = wall - m_workerSprite.getGlobalBounds().top;
		adjustment.y = distance;
	}
	else if (m_workerSprite.getGlobalBounds().height >(1920 - wall))
	{
		int distance = (1920 - wall) - m_workerSprite.getGlobalBounds().height;
		adjustment.y = distance;
	}

	if (adjustment != Vector2f(0,0))
	{
		m_workerSprite.move(m_workerSprite.getPosition() + adjustment);

		m_workerSprite.setRotation((float)atan2(0.1,0.1));
		deltaangle *= -1;
		nextangle = m_workerSprite.getRotation() + deltaangle;
	}
	else if (abs(m_workerSprite.getRotation() - nextangle) < 0.1f)
	{
		deltaangle *= -1;
		nextangle = m_workerSprite.getRotation() + deltaangle;
	}
	
	else
	{
		m_workerSprite.setRotation(m_workerSprite.getRotation()+ 0.01f * (nextangle - m_workerSprite.getRotation()));
		m_workerSprite.move(Vector2f(10 * (float)cos(m_workerSprite.getRotation()),10 * (float)sin(m_workerSprite.getRotation())));
	}
}
float Worker::rand_FloatRange(float a)
{
	float c;
	c = rand() % (int)a;
	return c;
}