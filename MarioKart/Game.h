#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode

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


/// <summary>
/// Michal Rapciak and Richie Buturla
/// </summary>
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
	
	sf::RenderWindow m_window;
};
#endif // !GAME_H