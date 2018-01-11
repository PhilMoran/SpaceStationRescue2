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
	if (empty == true)
	{
		Seek(Worker);
		if (sweepSprite.getPosition().x < Worker->m_workerSprite.getPosition().x + Worker->m_workerSprite.getGlobalBounds().width &&
			sweepSprite.getPosition().x + sweepSprite.getGlobalBounds().width > Worker->m_workerSprite.getPosition().x &&
			sweepSprite.getPosition().y < Worker->m_workerSprite.getPosition().y + Worker->m_workerSprite.getGlobalBounds().height &&
			sweepSprite.getGlobalBounds().height + sweepSprite.getPosition().y > Worker->m_workerSprite.getPosition().y)
		{
			sweepSprite.setTexture(sweepFullTex);
			Worker->alive = false;
			empty = false;
			sweepingArea = false;
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
void Sweeper::Seek(Worker * Worker)
{
	sf::Vector2f seekPosition = sweepSprite.getPosition();
	sf::Vector2f desired_velocity;
	//sweepSprite.setOrigin(65, 115);
	float maxSpeed = 0.2f;
	float maxForce = 3.0f;

	seekPosition = seekPosition + sweepVelocity;
	sweepVelocity = normalize(Worker->m_workerSprite.getPosition() - seekPosition) * maxSpeed;
	float rotation = sweepSprite.getRotation();

	if (maxSpeed > 0)
	{
		rotation = atan2f(sweepVelocity.x, -sweepVelocity.y);
		rotation = RadsToDegrees(rotation);
	}

	sweepSprite.setRotation(rotation);
	sweepSprite.move(sweepVelocity);
}
void Sweeper::Flee(Sprite Player)
{
	sf::Vector2f fleePosition = sweepSprite.getPosition();

	float maxSpeed = 0.2f;
	float maxForce = 3.0f;
	float rotation = Player.getRotation();

	fleePosition = fleePosition + sweepVelocity;
	sweepVelocity = normalize(Player.getPosition() + fleePosition) * maxSpeed;
	//steering = Player.getRotation() + maxSpeed;

	if (maxSpeed > 0)
	{
		rotation = atan2f(sweepVelocity.x, -sweepVelocity.y);
		rotation = RadsToDegrees(rotation);
	}

	sweepSprite.setRotation(rotation);
	sweepSprite.move(sweepVelocity);
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
float Sweeper::Distance(float x1, float y1,float x2, float y2)
{
	float distanceOfVision = sqrt((x2- x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	return distanceOfVision;
}