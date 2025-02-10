#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(125, 125);
	rect.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(75, 75));
	rect2.setPosition(112, 112);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(100, 100));
	rect3.setPosition(100, 100);
	rect3.setFillColor(sf::Color::Blue);

	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);

	//Render text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	rect4.setSize(sf::Vector2f(150, 150));
	rect4.setPosition(400, 400);
	rect4.setFillColor(sf::Color::Magenta);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u size = window->getSize();
	rect4.setPosition(size.x - rect4.getSize().x, size.y - rect4.getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect3);

	window->draw(rect2);

	window->draw(rect);

	window->draw(circle);

	window->draw(text);

	window->draw(rect4);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));

}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}