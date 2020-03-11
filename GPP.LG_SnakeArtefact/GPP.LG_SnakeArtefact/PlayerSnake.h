#pragma once
#include <iostream>
#include <fstream>
#include "BaseSnakeClass.h"

class PlayerSnake : public BaseSnakeClass
{
public:
	PlayerSnake(sf::VideoMode screenSize);
	~PlayerSnake();

	void setDirection(EDirection newDirection);
	void Update(sf::Event& event);
	void SaveData(std::string outputString);
	

private:
};

