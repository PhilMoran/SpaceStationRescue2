// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Worker.h"
#include "Nest.h"

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

	Level level;
	Worker *workerOne = new Worker(Vector2f(10, 10));

	Nest *nest = new Nest(Vector2f(2000,1000));

};

#endif // !GAME

