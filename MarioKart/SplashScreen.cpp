
#include <iostream> 
#include "SplashScreen.h"
#include "Game.h"


/// <summary>
/// @author Richard Buturla
/// @version 1.0
/// @date 04/02/2022
/// 
/// </summary>

SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialise(sf::Font& t_font)
{
	m_font = t_font;
	//load texture and setup sprite
	if (!m_splashTexture.loadFromFile("ASSETS/IMAGES/wallpaper.jpg"))
	{
		std::cout << "Error loading splash texture" << std::endl;
	}
	m_splashTexture.setRepeated( true );
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(Game::s_screenWidth), static_cast<int>(Game::s_screenHeight)));
	m_splashSprite.setPosition(0, 0);

	m_message.setFont(m_font);
	m_message.setString("Press any key to continue");
	m_message.setCharacterSize(60U);
	m_message.setStyle(sf::Text::Bold);
	m_message.setFillColor(sf::Color::White);
	m_message.setOutlineColor(sf::Color::Black);
	m_message.setOutlineThickness(2.0f);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xPosition = Game::s_screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xPosition, Game::s_screenHeight * 0.66f);
	m_proceedKeyPressed = false;

}

void SplashScreen::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_splashSprite);
	t_window.draw(m_message);
}

void SplashScreen::processInput(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		m_proceedKeyPressed = true;
	}
}

void SplashScreen::update(sf::Time t_deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		m_proceedKeyPressed = true;
	}
	if (m_proceedKeyPressed)
	{
		Game::currentState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;
}
