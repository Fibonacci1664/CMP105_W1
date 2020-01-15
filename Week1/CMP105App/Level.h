#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Level
{
public:
	Level(sf::RenderWindow* p_window);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();

	sf::RenderWindow* m_window;

	sf::RectangleShape m_rect_1;
	sf::RectangleShape m_rect_2;
	sf::RectangleShape m_rect_3;
	sf::RectangleShape m_rect_4;
	sf::CircleShape m_circle;

	sf::Font m_font;
	sf::Text m_text;
};