#include "Player.h"
Player::Player()
{

}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	//Note to self: put 0 on the axis you dont want your key press to have an effect on !
	if(input->isKeyDown(sf::Keyboard::Up))		move(0 , -getVelocity().y*dt);
	if(input->isKeyDown(sf::Keyboard::Down))	move(0, getVelocity().y * dt);
	if(input->isKeyDown(sf::Keyboard::Left))	move(-getVelocity().x * dt, 0);
	if(input->isKeyDown(sf::Keyboard::Right))	move(getVelocity().x * dt, 0);
}