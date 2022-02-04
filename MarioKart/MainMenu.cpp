
#include <iostream> 
#include "MainMenu.h"
#include "Game.h"


/// <summary>
/// Michael Rapciak and Richie Buturla
/// </summary>

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::setupButtons(sf::Font& t_font)
{
	m_topOffset = 50;
	m_verticalSpace = 100;
	m_buttonWidth = 200;
	m_leftOffset = (Game::s_screenWidth - m_buttonWidth) / 2;
	m_buttonHeight = 50;
	int textDropOffset = 10;
	sf::String m_menuText[] = { "Start The Game", "Help", "Exit Game" };
	m_font = t_font;

	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/button.png"))
	{
		std::cout << "Error loading the button texture" << std::endl;
	}
	for (int index = 0; index < m_optionCount; index++)
	{
		m_buttonSprite[index].setTexture(m_buttonTexture);
		m_buttonSprite[index].setPosition(m_leftOffset, m_verticalSpace * index + m_topOffset);

		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprite[index].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);
		
		m_buttonText[index].setFont(m_font);
		m_buttonText[index].setString(m_menuText[index]);
		m_buttonText[index].setFillColor(sf::Color::White);
		m_buttonText[index].setCharacterSize(24);
		sf::FloatRect textSize = m_buttonText[index].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonText[index].setPosition(m_leftOffset + textOffset, m_verticalSpace * index + m_topOffset + textDropOffset);
	}
}
