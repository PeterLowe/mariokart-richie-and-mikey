
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

/// <summary>
/// Sets up the buttons
/// </summary>
/// <param name="t_font">font used by text</param>
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
		m_buttonSprite[index].setTexture(m_buttonTexture); // sets the texture of the buttons
		m_buttonSprite[index].setPosition(m_leftOffset, m_verticalSpace * index + m_topOffset); // sets the position of the buttons

		sf::Vector2u textureSize = m_buttonTexture.getSize(); // sets the size of the texture
		m_buttonSprite[index].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y); // sets the scale of the texture 
		
		m_buttonText[index].setFont(m_font); // sets the font
		m_buttonText[index].setString(m_menuText[index]); // sets the menu text
		m_buttonText[index].setFillColor(sf::Color::White); // sets the colour
		m_buttonText[index].setCharacterSize(24);
		sf::FloatRect textSize = m_buttonText[index].getGlobalBounds(); // sets the global bounds (hitboxes)
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonText[index].setPosition(m_leftOffset + textOffset, m_verticalSpace * index + m_topOffset + textDropOffset);
	}
}

/// <summary>
/// Used to update the menu
/// </summary>
/// <param name="t_deltaTime"></param>
/// <param name="t_window"></param>
void MainMenu::update(sf::Time t_deltaTime, sf::Window& t_window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(t_window);
		if (mouseLocation.x > m_topOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)
		{
			if (mouseLocation.y < m_topOffset && mouseLocation.y && mouseLocation.y < m_topOffset + m_buttonHeight)
			{
				Game::currentState = GameState::Game;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpace && mouseLocation.y < m_topOffset + m_verticalSpace + m_buttonHeight)
			{
				Game::currentState = GameState::Help;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpace * 2 && mouseLocation.y < m_topOffset + m_verticalSpace * 2 + m_buttonHeight)
			{
				t_window.close();
			}
		}
	}
}

/// <summary>
/// used to render the sprites and text
/// </summary>
/// <param name="t_window">the window</param>
void MainMenu::render(sf::RenderWindow& t_window)
{
	for (int index = 0; index < m_optionCount; index++)
	{
		t_window.draw(m_buttonSprite[index]);
		t_window.draw(m_buttonText[index]);
	}
}