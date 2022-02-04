
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
}