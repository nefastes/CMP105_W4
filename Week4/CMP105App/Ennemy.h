#pragma once
#include "Framework/GameObject.h"
class Ennemy : public GameObject
{
public: 
	Ennemy();
	~Ennemy();

	void update(float dt) override;
	void sendWindowInfos(sf::RenderWindow* hwnd) { window = hwnd; };

private:
	sf::RenderWindow* window;
};