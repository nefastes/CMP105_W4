#include "Player.h"
Player::Player()
{
	counter = 0;
	isMoving = false;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	//Note to self: put 0 on the axis you dont want your key press to have an effect on !
	/*if (input->isKeyDown(sf::Keyboard::Up) || input->isKeyDown(sf::Keyboard::W))
	{
		move(0, -getVelocity().y * dt);
		isMoving = true;
	}
	if (input->isKeyDown(sf::Keyboard::Down) || input->isKeyDown(sf::Keyboard::S))
	{
		move(0, getVelocity().y * dt);
		isMoving = true;
	}*/
	if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::A))
	{
		move(-getVelocity().x * dt, 0);
		isMoving = true;
	}
	else if (input->isKeyDown(sf::Keyboard::Right) || input->isKeyDown(sf::Keyboard::D))
	{
		move(getVelocity().x * dt, 0);
		isMoving = true;
	}
	else isMoving = false;

	if (isMoving) update(dt);
}

void Player::update(float dt)
{
	if (counter == 10)
	{
		setTextureRect(sf::IntRect(15,0,15,21));
		++counter;
	}
	else if (counter == 20)
	{
		setTextureRect(sf::IntRect(0,0,15,21));
		counter = 0;
	}
	else ++counter;
}