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

	playerTex.loadFromFile("gfx/MarioSheetT.png");	//We need to load the entire texture first, and then focus our sprite view with setTextureRect
	player.setInput(input);
	player.setTexture(&playerTex);
	player.setTextureRect(sf::IntRect(0, 0, 15, 21));	//First init of the sprite texture rect
	player.setSize(sf::Vector2f(100.0f, 100.0f));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	player.setVelocity(sf::Vector2f(400.0f, 100.0f));

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

	mouseTex.loadFromFile("gfx/icon.png");
	mouse.setInput(input);
	mouse.setTexture(&mouseTex);
	mouse.setSize(sf::Vector2f(60.0f, 60.0f));
	window->setMouseCursorVisible(false);

	backgroundTex.loadFromFile("gfx/Level1_1.png");
	background.setTexture(&backgroundTex);
	background.setSize(sf::Vector2f(11038, window->getSize().y));
	background.setPosition(0, 0);

	camera.setView(window->getView());
	camera.sendWindowInfos(window);
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
	mouse.update(dt);
	camera.moveViewPos(sf::Vector2f(player.getPosition().x, window->getSize().y/2));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(background);
	window->draw(testSprite);
	window->draw(player);
	for (unsigned i = 0; i < 2; i++) window->draw(goombas[i]);
	window->draw(mouse);

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