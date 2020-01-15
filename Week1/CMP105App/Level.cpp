#include "Level.h"

Level::Level(sf::RenderWindow* p_window)
{
	m_window = p_window;

	// Initialise game objects.
	m_rect_1.setSize(sf::Vector2f(50, 50));
	m_rect_1.setOrigin(sf::Vector2f(m_rect_1.getSize().x / 2, m_rect_1.getSize().y / 2));
	m_rect_1.setPosition(100, 100);
	m_rect_1.setFillColor(sf::Color::Blue);

	m_rect_2.setSize(sf::Vector2f(100, 100));
	m_rect_2.setOrigin(sf::Vector2f(m_rect_2.getSize().x / 2, m_rect_2.getSize().y / 2));
	m_rect_2.setPosition(100, 100);
	m_rect_2.setFillColor(sf::Color::Green);

	m_rect_3.setSize(sf::Vector2f(150, 150));
	m_rect_3.setOrigin(sf::Vector2f(m_rect_3.getSize().x / 2, m_rect_3.getSize().y / 2));
	m_rect_3.setPosition(100, 100);
	m_rect_3.setFillColor(sf::Color::Red);

	m_rect_4.setSize(sf::Vector2f(150, 150));
	m_rect_4.setOrigin(sf::Vector2f(m_rect_3.getSize().x / 2, m_rect_3.getSize().y / 2));
	m_rect_4.setPosition(sf::Vector2f(p_window->getSize().x - 100, p_window->getSize().y - 100));
	m_rect_4.setFillColor(sf::Color::Green);

	m_circle.setRadius(50);
	m_circle.setOrigin(sf::Vector2f(m_circle.getRadius(), m_circle.getRadius()));
	m_circle.setPosition(sf::Vector2f(p_window->getSize().x / 2, p_window->getSize().y / 2));
	m_circle.setFillColor(sf::Color::Blue);
	m_circle.setOutlineColor(sf::Color::Red);
	m_circle.setOutlineThickness(5.0f);

	if (!m_font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	m_text.setFont(m_font);
	m_text.setString("Hello World!");
	m_text.setCharacterSize(24);
	m_text.setOrigin(sf::Vector2f(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2));
	m_text.setPosition(sf::Vector2f(p_window->getSize().x / 2, 50));
	m_text.setFillColor(sf::Color::Red);
}

Level::~Level()
{
}

// Handle user input.
void Level::handleInput()
{

}

// Update game objects.
void Level::update()
{
	m_rect_4.setPosition(sf::Vector2f(m_window->getSize().x - 100, m_window->getSize().y - 100));
}

// Render level.
void Level::render()
{
	beginDraw();
	m_window->draw(m_rect_4);
	m_window->draw(m_rect_3);
	m_window->draw(m_rect_2);
	m_window->draw(m_rect_1);
	m_window->draw(m_circle);
	m_window->draw(m_text);
	endDraw();
}

// Prep the buffer for drawing.
void Level::beginDraw()
{
	m_window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	m_window->display();
}