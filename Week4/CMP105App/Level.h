#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Player.h"
#include "Ennemy.h"
#include "Cursor.h"
#include "Background.h"
#include "Camera.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Level objects
	GameObject testSprite;
	sf::Texture texture;
	Player player;
	sf::Texture playerTex;
	Ennemy goombas[2];
	sf::Texture goombaTex;

	Cursor mouse;
	sf::Texture mouseTex;

	Background background;
	sf::Texture backgroundTex;

	Camera camera;
};