#pragma once
#include <SFML/Graphics.hpp>
#include "BaseSnakeClass.h"

class Food
{
	public:

	Food();
	~Food();

	void drawFood(sf::RenderWindow& window);
	void spawnFood(sf::VideoMode screenSize, BaseSnakeClass& snake);

	int getScoreAmount() { return scoreAmount; }
	bool getActive() { return isActive; }
	sf::Vector2i getPosition() { return position; }

	void setActive(bool active) { isActive = active; }
	void setPosition(sf::Vector2i newPosition) { position = newPosition; }

	// This overloaded function is purely optional, as I can pass in two parameters to the function that takes a vector2u but surround them with {}.
	void setPosition(unsigned int newX, unsigned int newY) { position.x = newX, position.y = newY; } 

	private:

	sf::RectangleShape rectShape{ { 10, 10 } };
	int scoreAmount = 0;
	bool isActive = false;
	sf::Vector2i position { 0, 0 };
};

