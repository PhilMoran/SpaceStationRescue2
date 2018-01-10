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
void Worker::Load()
{
	
	m_workerSprite.setTexture(m_workerTexture);
	m_workerSprite.setOrigin(29, 52);

	
	
}

void Worker::Draw(RenderWindow& _window)
{
	
	if (alive == true)
	{
		_window.draw(m_workerSprite);

	}
	
	
	
}
void Worker::Collected(Sprite & Player)
{
	if (alive == true)
	{
		if (m_workerSprite.getPosition().x < Player.getPosition().x + Player.getGlobalBounds().width &&
			m_workerSprite.getPosition().x + m_workerSprite.getGlobalBounds().width > Player.getPosition().x &&
			m_workerSprite.getPosition().y < Player.getPosition().y + Player.getGlobalBounds().height &&
			m_workerSprite.getGlobalBounds().height + m_workerSprite.getPosition().y > Player.getPosition().y)
		{
			alive = false;
			collected++;
		}
		
	}
	
}
void Worker::Wander()
{
	if (alive == true)
	{
		sf::Time wanderClock = clock.getElapsedTime();

		Vector2f WorkerPosition = m_workerSprite.getPosition();
		Vector2f WanderVelocity = Vector2f(0, 0);

		float maxSpeed = 0.2f;

		WorkerPosition = WorkerPosition + WanderVelocity;
		WanderVelocity = normalize(WanderPos - WorkerPosition) * maxSpeed;
		float rotation = m_workerSprite.getRotation();

		if (maxSpeed > 0)
		{
			rotation = atan2f(WanderVelocity.x, -WanderVelocity.y);
			rotation = RadsToDegrees(rotation);
		}


		if (wanderClock.asSeconds() >= 3)
		{
			WanderPos.x = WorkerPosition.x + 500 * cos(rand());
			WanderPos.y = WorkerPosition.y + 500 * cos(rand());
			clock.restart();
		}
		float distance = sqrt((WorkerPosition.x - WanderPos.x) * 2 + (WorkerPosition.y - WanderPos.y) * 2);
		if (distance < 1 || WorkerPosition.y < 180 || WorkerPosition.x < 180 || WorkerPosition.x > 3615 || WorkerPosition.y >2070)
		{
			WanderPos.x = WorkerPosition.x + 500 * cos(rand());
			WanderPos.y = WorkerPosition.y + 500 * cos(rand());
			clock.restart();
		}
		m_workerSprite.setRotation(rotation);
		m_workerSprite.move(WanderVelocity); 
	}
}
float Worker::rand_FloatRange(float a, float b)
{
	float c;
	c = rand() % (int)a + (-(int)b);
	return c;
	
}
float Worker::RadsToDegrees(float rads)
{
	float degs = rads * 180 / 3.14;
	return degs;
}
sf::Vector2f Worker::normalize(sf::Vector2f & source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}