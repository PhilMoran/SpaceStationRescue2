

#include "Game.h"
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

Game::Game() :
	m_window{ sf::VideoMode(1280,1280), "SpaceStationRescue2" },
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
		nest->Update(playerSprite);
		powerUp->Update(playerSprite);
		processEvents(); // as many as possible

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
		checkAIAlive();
		

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

	playerSprite.move(sin(playerSprite.getRotation()*3.14159265 / 180)*playerVelocity.x, -cos(playerSprite.getRotation()*3.14159265 / 180)*playerVelocity.x);

	
	

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
	if (powerUp->radar == true)
	{
		MyView.zoom(2);
	}
	m_window.setView(MyView);
	

	level.Draw(&m_window);
	powerUp->Draw(m_window);
	workerOne->Draw(m_window);
	workerTwo->Draw(m_window);
	workerThree->Draw(m_window);
	workerFour->Draw(m_window);
	workerFive->Draw(m_window);

	predOne->Draw(m_window);

	sweepOne->Draw(m_window);
	nest->Draw(m_window);
	m_window.draw(playerSprite);
	m_window.draw(workerText);
	m_window.display();
	
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::LoadTextures()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\Player.png"))
	{
		// error...
	}
	if (!workerFont.loadFromFile("Rumble Brave.otf"))
	{
		cout << "ERRRRRROR" << endl;
	}
	
	workerText.setFont(workerFont);
	workerText.setCharacterSize(72);
	workerText.setFillColor(Color::Red);
	// set the text style
	workerText.setStyle(sf::Text::Bold);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::LoadSprites()
{

	workerOne->Load();
	workerTwo->Load();
	workerThree->Load();
	workerFour->Load();
	workerFive->Load();

	predOne->Load();

	sweepOne->Load();

	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(65,49);
	playerSprite.setPosition(600, 600);

}
void Game::checkAIAlive()
{
	if (workerOne->alive == true)
	{
		workerOne->Wander();
		workerOne->Collected(playerSprite);
		if (sweepOne->Distance(workerOne->m_workerSprite.getPosition().x, workerOne->m_workerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y) < 400 && sweepOne->empty == true)
		{
			sweepOne->sweepingArea = true;
			sweepOne->CollectWorker(workerOne);
		}

		if (workerOne->alive == false)
		{
			workerNum++;
		}
	}

	if (workerTwo->alive == true)
	{
		workerTwo->Wander();
		workerTwo->Collected(playerSprite);
		if (sweepOne->Distance(workerTwo->m_workerSprite.getPosition().x, workerTwo->m_workerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y) < 400 && sweepOne->empty == true)
		{
			sweepOne->sweepingArea = true;
			sweepOne->CollectWorker(workerTwo);
		}
		if (workerTwo->alive == false)
		{
			workerNum++;
		}
	}

	if (workerThree->alive == true)
	{
		workerThree->Wander();
		workerThree->Collected(playerSprite);
		if (sweepOne->Distance(workerThree->m_workerSprite.getPosition().x, workerThree->m_workerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y) < 400 && sweepOne->empty == true)
		{
			sweepOne->sweepingArea = true;
			sweepOne->CollectWorker(workerThree);
		}
		if (workerThree->alive == false)
		{
			workerNum++;
		}
	}
	if (workerFour->alive == true)
	{
		workerFour->Wander();
		workerFour->Collected(playerSprite);
		if (sweepOne->Distance(workerFour->m_workerSprite.getPosition().x, workerFour->m_workerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y) < 400&& sweepOne->empty == true)
		{
			sweepOne->sweepingArea = true;
			sweepOne->CollectWorker(workerFour);
		}
		if (workerFour->alive == false)
		{
			workerNum++;
		}
	}
	if (workerFive->alive == true)
	{
		workerFive->Wander();
		workerFive->Collected(playerSprite);
		if (sweepOne->Distance(workerFive->m_workerSprite.getPosition().x, workerFive->m_workerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y) < 400 && sweepOne->empty == true)
		{
			sweepOne->sweepingArea = true;
			sweepOne->CollectWorker(workerFive);
		}
		if (workerFive->alive == false)
		{
			workerNum++;
		}

	}
	if (sweepOne->Distance(playerSprite.getPosition().x, playerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y)<300)
	{
		sweepOne->Flee(playerSprite);
	}
	else if (sweepOne->sweepingArea == false && sweepOne->Distance(playerSprite.getPosition().x, playerSprite.getPosition().y, sweepOne->sweepSprite.getPosition().x, sweepOne->sweepSprite.getPosition().y)>300)
	{
		sweepOne->Wander();
	}
	predOne->Seek(playerSprite);
	workerText.setString("Workers Rescued = " + std::to_string(workerNum)+"/5");
	if (powerUp->radar == false)
	{
		workerText.setPosition(playerSprite.getPosition().x - 300, playerSprite.getPosition().y - 500);
		workerText.setScale(1, 1);
	}
	else if (powerUp->radar == true)
	{
		workerText.setPosition(playerSprite.getPosition().x - 500, playerSprite.getPosition().y - 1000);
		workerText.setScale(2, 2);
	}
}
sf::Vector2f Game::normalize(sf::Vector2f & source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}
