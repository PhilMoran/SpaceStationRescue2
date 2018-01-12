
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Worker.h"
#include "Predator.h"
#include "Sweeper.h"
#include "Nest.h"
#include "PowerUp.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void AIMovement();
	void Seek();
	void checkAIAlive();
	void Flee();
	void PlayerMovement();
	void LoadTextures();
	void LoadSprites();
	sf::Vector2f normalize(sf::Vector2f& source);

	sf::RenderWindow m_window; // main SFML window
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	sf::Vector2f playerVelocity;
	sf::Vector2f seekVelocity;
	float steering;
	sf::Vector2f playerVelocityAdditive;
	sf::Vector2f direction;
	sf::Clock clock;
	float accceleration = 0;
	sf::Time elapsed1;
	sf::Font workerFont;
	sf::Text workerText;

	int workerNum = 0;

	Level level;
	Worker *workerOne = new Worker(Vector2f(300, 300));
	Worker *workerTwo = new Worker(Vector2f(350, 1950));
	Worker *workerThree = new Worker(Vector2f(3600, 1870));
	Worker *workerFour = new Worker(Vector2f(3600, 300));
	Worker *workerFive = new Worker(Vector2f(1970, 1170));
	Predator *predOne = new Predator(Vector2f(0, 0));
	Sweeper *sweepOne = new Sweeper(Vector2f(1500, 300));
	Nest *nest = new Nest(Vector2f(2000, 1000));
	PowerUp *powerUp = new PowerUp(Vector2f(2500, 1500));
	
};

#endif // !GAME

