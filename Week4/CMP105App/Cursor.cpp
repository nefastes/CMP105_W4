#include "Cursor.h"
Cursor::Cursor()
{

}

Cursor::~Cursor()
{

}

void Cursor::update(float dt)
{
	setPosition(input->getMouseX(), input->getMouseY());
}