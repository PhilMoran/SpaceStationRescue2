#include "Sweeper.h"

Sweeper::Sweeper()
{

}
Sweeper::Sweeper(sf::Vector2f position)
{

	sweepPos = position;
	sweepSprite.setPosition(sweepPos);

	if (!sweepEmptyTex.loadFromFile("ASSETS\\IMAGES\\emptySweeper.png"))
	{
		// error...
	}
	if (!sweepFullTex.loadFromFile("ASSETS\\IMAGES\\fullSweeper.png"))
	{
		// error...
	}
}

Sweeper::~Sweeper()
{
}
void Sweeper::Load()
{

	sweepSprite.setTexture(sweepEmptyTex);
	sweepSprite.setOrigin(75, 76);



}

void Sweeper::Draw(RenderWindow& _window)
{

	if (alive == true)
	{
		_window.draw(sweepSprite);

	}



}
void Sweeper::CollectWorker(Worker* Worker)
{
	if (alive == true)
	{
		if (sweepSprite.getPosition().x < Worker->m_workerSprite.getPosition().x + Worker->m_workerSprite.getGlobalBounds().width &&
			sweepSprite.getPosition().x + sweepSprite.getGlobalBounds().width > Worker->m_workerSprite.getPosition().x &&
			sweepSprite.getPosition().y < Worker->m_workerSprite.getPosition().y + Worker->m_workerSprite.getGlobalBounds().height &&
			sweepSprite.getGlobalBounds().height + sweepSprite.getPosition().y > Worker->m_workerSprite.getPosition().y)
		{
			sweepSprite.setTexture(sweepFullTex);
			Worker->alive = false;
		}
	}

}
void Sweeper::Wander()
{
	if (alive == true)
	{
		sf::Time wanderClock = clock.getElapsedTime();

		Vector2f sweepPosition = sweepSprite.getPosition();
		Vector2f WanderVelocity = Vector2f(0, 0);

		float maxSpeed = 0.2f;

		sweepPosition = sweepPosition + WanderVelocity;
		WanderVelocity = normalize(wanderPos - sweepPosition) * maxSpeed;
		float rotation = sweepSprite.getRotation();

		if (maxSpeed > 0)
		{
			rotation = atan2f(WanderVelocity.x, -WanderVelocity.y);
			rotation = RadsToDegrees(rotation);
		}


		if (wanderClock.asSeconds() >= 3)
		{
			wanderPos.x = sweepPosition.x + 500 * cos(rand());
			wanderPos.y = sweepPosition.y + 500 * cos(rand());
			clock.restart();
		}
		float distance = sqrt((sweepPosition.x - wanderPos.x) * 2 + (sweepPosition.y - wanderPos.y) * 2);
		if (distance < 1 || sweepPosition.y < 180 || sweepPosition.x < 180 || sweepPosition.x > 3615 || sweepPosition.y >2070)
		{
			wanderPos.x = sweepPosition.x + 500 * cos(rand());
			wanderPos.y = sweepPosition.y + 500 * cos(rand());
			clock.restart();
		}
		sweepSprite.setRotation(rotation);
		sweepSprite.move(WanderVelocity);
	}
}
float Sweeper::rand_FloatRange(float a, float b)
{
	float c;
	c = rand() % (int)a + (-(int)b);
	return c;

}
float Sweeper::RadsToDegrees(float rads)
{
	float degs = rads * 180 / 3.14;
	return degs;
}
sf::Vector2f Sweeper::normalize(sf::Vector2f & source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}