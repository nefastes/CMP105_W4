#include "Ennemy.h"
Ennemy::Ennemy()
{

}

Ennemy::~Ennemy()
{

}

void Ennemy::update(float dt)
{
	move(getVelocity().x * dt, getVelocity().y * dt);
	if (getPosition().x < 0 + getSize().x / 2)
	{
		setPosition(0 + getSize().x / 2, getPosition().y);
		setVelocity(sf::Vector2f(getVelocity().x * -1.0f, getVelocity().y));
	}
	if (getPosition().x > window->getSize().x - getSize().x / 2)
	{
		setPosition(window->getSize().x - getSize().x / 2, getPosition().y);
		setVelocity(sf::Vector2f(getVelocity().x * -1.0f, getVelocity().y));
	}
	if (getPosition().y < 0 + getSize().y / 2)
	{
		setPosition(getPosition().x, 0 + getSize().y / 2);
		setVelocity(sf::Vector2f(getVelocity().x, getVelocity().y * -1.0f));
	}
	if (getPosition().y > window->getSize().y - getSize().y / 2)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y / 2);
		setVelocity(sf::Vector2f(getVelocity().x, getVelocity().y * -1.0f));
	}
}