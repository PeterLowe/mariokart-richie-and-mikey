#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>

/// <summary>
/// Michal Rapciak
///  class to handle simple menu interaction
/// </summary>
class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void setupButtons(sf::Font& t_font);
	void update(sf::Time t_deltaTime, sf::Window& t_window);
	void render(sf::RenderWindow& t_window);

protected:
	static const int m_optionCount = 3; // amount of options
	sf::Texture m_buttonTexture; // texture for buttons
	sf::Sprite m_buttonSprite[m_optionCount]; // sprites for buttons
	sf::Text m_buttonText[m_optionCount]; // text for buttons 
	sf::Font m_font; // font used by buttons
	sf::Texture m_bgTexture; // texture used for background
	sf::Sprite m_bgSprite; // sprite used for background
	float m_topOffset{ 0.0f }; // used for top left y co-ordinate of button
	float m_leftOffset{ 0.0f }; // used for top left x co-ordinate of button
	float m_verticalSpace{ 0.0f }; // used for spacing between buttons
	float m_buttonWidth{ 0.0f }; // used for button width
	float m_buttonHeight{ 0.0f }; // used for button height
	
};

#endif // !MAINMENU_H