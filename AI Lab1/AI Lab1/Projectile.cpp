#include "Projectile.h"

/*void Projectile::loadBullet()
{
	sf::Texture LaserTexture;
	LaserTexture.loadFromFile("images/laser.png");
	std::vector<sf::Sprite>Laser(1000, sf::Sprite(LaserTexture));
}
void Projectile::updateBullet()
{
	// Don't let the user hold down the space key. Has to tap it.
	if (curKeyState.isKeyDown(Keys.Space) && oldKeyState.isKeyUp(Keys.Space))
	{
		if (!justShot)
		{
			particles.Add(new Particle(tank.Position));
			justShot = true;
		}
	}

	if (justShot)
	{
		if (shotTimer < shotDelay)
		{
			shotTimer += elapsed; // in seconds
		}
		else { justShot = false; shotTimer = 0; }
	}

	for (int i = 0; i < particles.Count; i++)
	{
		particles[i].update();
		// if (collision or past end of screen)
		particles.remove(particles[i]); // one way
		particles[i].active = false; // another way
	}

	oldKeyState = curKeyState;
}*/