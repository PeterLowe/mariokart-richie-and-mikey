#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode

#include "SplashScreen.h"
#include "Licence.h"

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
	GameState Game::currentState = GameState::License;

protected:
	void	processEvents();
	void	update(sf::Time);
	void	render();
	void loadContent();
	
	sf::RenderWindow m_window;

	SplashScreen m_splashScreen; //used to run splash screen
	Licence m_licenceScreen;

	sf::Font m_arialFont;
};
#endif // !GAME_H