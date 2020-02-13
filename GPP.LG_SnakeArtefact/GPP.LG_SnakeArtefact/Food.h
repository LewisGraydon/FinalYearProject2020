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
	sf::Vector2u getPosition() { return position; }

	void setActive(bool active) { isActive = active; }
	void setPosition(sf::Vector2u newPosition) { position = newPosition; }
	void setPosition(unsigned int newX, unsigned int newY) { position.x = newX, position.y = newY; }

	private:

	sf::CircleShape shape;
	int scoreAmount;
	bool isActive;
	sf::Vector2u position;
};

