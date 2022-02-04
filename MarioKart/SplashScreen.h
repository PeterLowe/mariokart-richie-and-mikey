#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Richard Buturla
/// 
/// Simple class to display full screen texture
/// and text message and wait for anykey
/// </summary>
class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();
	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void processInput(sf::Event t_event);
	void update(sf::Time t_deltaTime);



	

protected:
	sf::Texture m_splashTexture; //texture of diamond wallpaper square
	sf::Sprite m_splashSprite;//sprite for background
	sf::Font m_font; //text
	sf::Text m_message; //text to display space message 
	bool m_proceedKeyPressed{ false }; //will go from event to update loop

	
};

#endif // !SPLASHSCREEN_H
