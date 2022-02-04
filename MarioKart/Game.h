#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode




/// <summary>
/// Michal Rapciak and Richie Buturla
/// </summary>
class Game
{
public:
	Game();
	void run();
	
protected:
	void	processEvents();
	void	update(sf::Time);
	void	render();
	
	sf::RenderWindow m_window;
};
#endif // !GAME_H