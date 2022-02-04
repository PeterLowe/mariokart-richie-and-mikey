#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode




/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// @brief main game class conatins main and run game loop.
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