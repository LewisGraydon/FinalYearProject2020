#pragma once
#include "BaseSnakeClass.h"

class AISnake : public BaseSnakeClass
{
public:
	AISnake(sf::VideoMode screenSize);
	~AISnake();

	void Update(sf::Event& event);

private:

};

