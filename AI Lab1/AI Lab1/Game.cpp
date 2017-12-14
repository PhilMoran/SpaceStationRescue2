// author Peter Lowe

#include "Game.h"
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

Game::Game() :
	m_window{ sf::VideoMode(1280,1280), "SpaceStationRescue2"  },
	m_exitGame{false} //when true game will exit
{
	LoadTextures(); // load font 
	LoadSprites(); // load texture
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		PlayerMovement();
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	
	

	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			if (sf::Keyboard::A == event.key.code)
			{
				playerSprite.setRotation(playerSprite.getRotation() - 5);
			
			}
			
			if (sf::Keyboard::D == event.key.code)
			{
				playerSprite.setRotation(playerSprite.getRotation() + 5);
				

			}
			if (sf::Keyboard::W == event.key.code)
			{
				playerVelocity.x += 0.1;
				if (playerVelocity.x >= 1.0f)
				{
					playerVelocity.x = 1.0f;
				}
				
			}

			if (sf::Keyboard::S == event.key.code)
			{
				playerVelocity.x -= 0.1;
				if (playerVelocity.x <= -1.0f)
				{
					playerVelocity.x = -1.0f;
				}
			}

		}
		
	}
}


void Game::Flee()
{
	/*Velocity = my.position - target.position
	Velocity = normalize(velocity)
	Velocity = velocity * maxSpeed
	Orientation = getNewOrientation(orientation, velocity)*/
}
void Game::PlayerMovement()
{

	if (playerSprite.getPosition().y <-500)
	{
		playerSprite.setPosition(playerSprite.getPosition().x, 2200);
	}
	if (playerSprite.getPosition().y >3500)
	{
		playerSprite.setPosition(playerSprite.getPosition().x, 0);
	}
	if (playerSprite.getPosition().x>5000)
	{
		playerSprite.setPosition(0, playerSprite.getPosition().y);
	}
	if (playerSprite.getPosition().x <-500)
	{
		playerSprite.setPosition(4000, playerSprite.getPosition().y);
	}
	playerSprite.setOrigin(305, 165);

	playerSprite.move(sin(playerSprite.getRotation()*3.14159265 / 180)*playerVelocity.x, -cos(playerSprite.getRotation()*3.14159265 / 180)*playerVelocity.x);

	
	std::cout << playerVelocity.x << std::endl;
	

	//Sprite.Move (0, -100 * ElapsedTime);
	
}
/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);

	sf::View MyView;
	MyView.setCenter(playerSprite.getPosition().x, playerSprite.getPosition().y);
	m_window.setView(MyView);

	m_window.draw(playerSprite);
	
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::LoadTextures()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\PLAYER.png"))
	{
		// error...
	}

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::LoadSprites()
{
	
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
	playerSprite.setPosition(0, 0);
	playerSprite.setScale(0.2, 0.2);
}

sf::Vector2f Game::normalize(sf::Vector2f & source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}
