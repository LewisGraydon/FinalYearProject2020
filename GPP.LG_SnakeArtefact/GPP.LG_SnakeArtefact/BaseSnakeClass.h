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
	virtual void setDirection(EDirection newDirection) { direction = newDirection; }

	int getScore() { return score; }
	void setScore(int amount) { score += amount; }

	bool getIsAlive() { return aliveStatus; }
	void setIsAlive(bool isAlive) { aliveStatus = isAlive; }

	float getLengthOfASide() { return lengthOfASide; }
	void moveSnake();
	void drawSnake(sf::RenderWindow& window, sf::Color colour);
	virtual void Update(sf::Event& event) { };

private:

	std::vector<sf::Vector2i>* snakeSegments = new std::vector<sf::Vector2i>();
	EDirection direction = EDirection::eNone;
	sf::VideoMode sizeOfScreen;
	int score = 0;
	float lengthOfASide = 10.0f;
	bool aliveStatus = true;
};

