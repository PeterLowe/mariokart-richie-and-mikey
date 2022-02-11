
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
#include "Licence.h"
#include "MainMenu.h"
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
GameState Game::currentState = GameState::License;

 
/// <summary>
/// @brief main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_window(sf::VideoMode(static_cast<unsigned>(s_screenWidth),static_cast<unsigned>(s_screenHeight)), "MarioKart", sf::Style::Default)
{
	loadContent();
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
			m_splashScreen.processInput(event);
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
	switch (currentState)
	{
	case GameState::None:
		break;
	case GameState::License:
		m_licenceScreen.update(time);
		break;
	case GameState::Splash:
		m_splashScreen.update(time);
		break;
	case GameState::MainMenu:
		m_mainMenu.update(time, m_window);
		break;
	case GameState::Help:
		break;
	case GameState::Game:
		break;
	default:
		break;
	}
}

void Game::render()
{
	m_window.clear();
	switch (currentState)
	{
	case GameState::None:
		break;
	case GameState::License:
		m_licenceScreen.render(m_window);
		break;
	case GameState::Splash:
		m_splashScreen.render(m_window); 
		break;
	case GameState::MainMenu:
		m_mainMenu.render(m_window);
		break;
	case GameState::Help:
		break;
	case GameState::Game:
		break;
	default:
		break;
	}
	m_window.display();
}

void Game::loadContent()
{
	if (!m_arialFont.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error loading font";
	}

	m_splashScreen.initialise(m_arialFont);
	m_licenceScreen.initialise(m_arialFont);
	m_mainMenu.setupButtons(m_arialFont);
}
