/// <summary>
/// Richard Buturla
/// </summary>

#include "Licence.h"
#include "Game.h"


Licence::Licence()
{
}


Licence::~Licence()
{
}

/// <summary>
/// setup font and message
/// </summary>
/// <param name="t_font">font loaded in main game</param>
void Licence::initialise(sf::Font& t_font)
{
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setString("Hand Made by Richie and Michal");
	m_message.setCharacterSize(24);
	m_message.setFillColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xPosition = Game::s_screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xPosition, 120.0f);
	m_culmulativeTime = sf::seconds(0);
}

/// <summary>
/// draw text
/// </summary>
/// <param name="t_window"></param>
void Licence::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_message);
}

void Licence::update(sf::Time t_deltaTime)
{
	m_culmulativeTime += t_deltaTime;
	if (m_culmulativeTime.asSeconds() > 1.5)
	{
		Game::currentState = GameState::Splash;
	}
}
