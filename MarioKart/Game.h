#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode

#include "SplashScreen.h"
#include "Licence.h"
#include "MainMenu.h"

/// <summary>
/// Michal Rapciak and Richie Buturla
/// </summary>
enum class
	GameState
{
	None,
	License,
	Splash,
	MainMenu,
	Help,
	Game
};

class Game
{
public:
	Game();
	void run();
	static float s_screenWidth;
	static float s_screenHeight;
	static GameState currentState;

protected:
	void	processEvents();
	void	update(sf::Time);
	void	render();
	void loadContent();
	
	sf::RenderWindow m_window;

	SplashScreen m_splashScreen; //used to run splash screen
	Licence m_licenceScreen;
	MainMenu m_mainMenu;

	sf::Font m_arialFont;
};
#endif // !GAME_H