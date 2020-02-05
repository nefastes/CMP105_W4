#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	playerTex.loadFromFile("gfx/Mushroom.png");
	player.setInput(input);
	player.setTexture(&playerTex);
	player.setSize(sf::Vector2f(100.0f, 100.0f));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	player.setVelocity(sf::Vector2f(100.0f, 100.0f));

	goombaTex.loadFromFile("gfx/Goomba.png");
	goomba.setTexture(&goombaTex);
	goomba.setSize(sf::Vector2f(100.0f, 100.0f));
	goomba.setOrigin(goomba.getSize().x / 2, goomba.getSize().y / 2);
	goomba.setPosition(1000, 200);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(testSprite);
	window->draw(player);
	window->draw(goomba);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}