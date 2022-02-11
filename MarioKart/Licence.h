#ifndef LICENCE_H
#define LICENCE_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Richard Buturla
/// 
/// \brief simple page to display Licence text for fixed period.
/// 
/// </summary>
class Licence
{
public:
	Licence();
	~Licence();	

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

protected:
	sf::Font m_font;
	sf::Text m_message;
	sf::Time m_culmulativeTime;
};

#endif // !LICENCE_H