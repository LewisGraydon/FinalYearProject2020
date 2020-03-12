#pragma once
#include <iostream>
#include <fstream>
#include "BaseSnakeClass.h"

class PlayerSnake : public BaseSnakeClass
{
public:
	PlayerSnake(sf::VideoMode screenSize, sf::Vector2i minBounds, sf::Vector2i maxBounds);
	~PlayerSnake();

	void setDirection(EDirection newDirection);
	void Update(sf::Event& event, sf::RenderWindow& window, sf::VideoMode screenSize);
	void SaveData(sf::RenderWindow& window, sf::VideoMode screenSize);

private:

	sf::Vector2i minGameBounds = {};
	sf::Vector2i maxGameBounds = {};
	sf::Keyboard::Key previousKey = sf::Keyboard::Key::F12;
};

