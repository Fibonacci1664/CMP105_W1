// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Level.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;

// For handling window events: Close and Resize.
void windowProcess(sf::RenderWindow* window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			window->setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			break;
		default:
			// Don't handle other events.
			break;
		}
	}
}

int main()
{
	//Create the window.
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "CMP105_W1");

	// Initialise input and level objects.
	Level level(&window);

	// Game Loop.
	while (window.isOpen())
	{
		// Handle window events, closing or resizing.
		windowProcess(&window);
		
		// Call standard game loop functions (input, update and render).
		level.handleInput();
		level.update();
		level.render();
	}
}

