
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SplashScreen.h"
#include <iostream>
/*
Michael Rapciak and Richie Buturla
Sessions:

*/


int main()
{ 
	Game game; 
	game.run(); 
}

float Game::s_screenWidth = 600;
float Game::s_screenHeight = 400;
GameState Game::currentState = GameState::Splash;

 
/// <summary>
/// @brief main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_window(sf::VideoMode(static_cast<unsigned>(s_screenWidth),static_cast<unsigned>(s_screenHeight)), "MarioKart", sf::Style::Default)
{
	//this is temporary run check. change after
	sf::Font m_font;
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error loading font";
	}
	m_splashscreen.initialise(m_font);
}

/// <summary>
/// @brief main game loop.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{		
			timeSinceLastUpdate -= timePerFrame;

			processEvents();
			update(timePerFrame);		
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		switch (currentState)
		{
		case GameState::None:
			break;
		case GameState::License:
			break;
		case GameState::Splash:
			m_splashscreen.processInput(event);
			break;
		case GameState::MainMenu:
			break;
		case GameState::Help:
			break;
		case GameState::Game:
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time time)
{
}

void Game::render()
{
	m_window.clear();
	m_splashscreen.render(m_window);
	m_window.display();
}