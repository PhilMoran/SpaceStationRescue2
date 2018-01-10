#include "Predator.h"
Predator::Predator()
{

}
Predator::Predator(sf::Vector2f position)
{
	predPos = position;
	predSprite.setPosition(predPos);

	if (!predTex.loadFromFile("ASSETS\\IMAGES\\Predator.png"))
	{
		cout << "ERROR" << endl;
	}
}
Predator::~Predator()
{

}
void Predator::Load()
{
	predSprite.setTexture(predTex);
}

void Predator::Draw(RenderWindow& _window)
{
	if (alive == true)
	{
		_window.draw(predSprite);
	}
}
void Predator::Seek(Sprite & Player)
{
	sf::Vector2f seekPosition = predSprite.getPosition();
	sf::Vector2f desired_velocity;
	predSprite.setOrigin(65, 115);
	float maxSpeed = 0.2f;
	float maxForce = 3.0f;

	seekPosition = seekPosition + predVelocity;
	predVelocity = normalize(Player.getPosition() - seekPosition) * maxSpeed;
	float rotation = predSprite.getRotation();

	if (maxSpeed > 0)
	{
		rotation = atan2f(predVelocity.x, -predVelocity.y);
		rotation = RadsToDegrees(rotation);
	}

	predSprite.setRotation(rotation);
	predSprite.move(predVelocity);
}
float Predator::RadsToDegrees(float rads)
{
	float degs = rads * 180 / 3.14;
	return degs;
}
Vector2f Predator::normalize(sf::Vector2f & source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}