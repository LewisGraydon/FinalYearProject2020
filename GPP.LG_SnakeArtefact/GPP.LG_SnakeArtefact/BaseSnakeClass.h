#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#define InvalidPosition -1

class BaseSnakeClass
{
public:

	enum EDirection
	{
		eNone,
		eUp,
		eDown,
		eLeft,
		eRight
	};

	BaseSnakeClass(sf::VideoMode screenSize);
	~BaseSnakeClass();

	std::vector<sf::Vector2i> &getSnakeSegments() { return *snakeSegments; }
	EDirection getDirection() { return direction; }
	int getScore() { return score; }

	void setDirection(EDirection newDirection) { direction = newDirection; }
	void moveSnake();
	void drawSnake(sf::RenderWindow& window, sf::Color colour);

private:

	std::vector<sf::Vector2i>* snakeSegments;
	EDirection direction = EDirection::eNone;
	sf::VideoMode sizeOfScreen;
	int score = 0;
};

