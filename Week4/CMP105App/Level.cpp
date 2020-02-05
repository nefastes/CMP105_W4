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
	goombas[0].sendWindowInfos(window);
	goombas[0].setTexture(&goombaTex);
	goombas[0].setSize(sf::Vector2f(100.0f, 100.0f));
	goombas[0].setOrigin(goombas[0].getSize().x / 2, goombas[0].getSize().y / 2);
	goombas[0].setPosition(1000, 200);
	goombas[0].setVelocity(sf::Vector2f(200.0f, 100.0f));

	goombas[1].sendWindowInfos(window);
	goombas[1].setTexture(&goombaTex);
	goombas[1].setSize(sf::Vector2f(100.0f, 100.0f));
	goombas[1].setOrigin(goombas[1].getSize().x / 2, goombas[1].getSize().y / 2);
	goombas[1].setPosition(100, 800);
	goombas[1].setVelocity(sf::Vector2f(-200.0f, 400.0f));
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
	for (unsigned i = 0; i < 2; i++) goombas[i].update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(testSprite);
	window->draw(player);
	for (unsigned i = 0; i < 2; i++) window->draw(goombas[i]);

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