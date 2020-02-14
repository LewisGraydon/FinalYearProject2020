#include "BaseSnakeClass.h"

BaseSnakeClass::BaseSnakeClass(sf::VideoMode screenSize) : sizeOfScreen(screenSize)
{
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2)); 
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2 - 10));
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2 - 20));
}

BaseSnakeClass::~BaseSnakeClass()
{
}

void BaseSnakeClass::moveSnake()
{
	sf::Vector2i temp;
	sf::Vector2i previousPosition(InvalidPosition, InvalidPosition);
	sf::Vector2i velocity(0,0);

	switch (direction)
	{
	case eNone:
		break;

	case eUp:
		velocity.x = 0;
		velocity.y = -1;
		break;

	case eDown:
		velocity.x = 0;
		velocity.y = 1;
		break;

	case eLeft:
		velocity.x = -1;
		velocity.y = 0;
		break;

	case eRight:
		velocity.x = 1;
		velocity.y = 0;
		break;

	default:
		break;
	}

	for (sf::Vector2i& i : getSnakeSegments())
	{
		if (previousPosition.x == InvalidPosition && previousPosition.y == InvalidPosition)
		{
			previousPosition = i;
			i.x += velocity.x;
			i.y += velocity.y;
		}
		else
		{
			temp = i;
			i = previousPosition;       //pop and push of the list
			previousPosition = temp;
		}
	}
}

void BaseSnakeClass::drawSnake(sf::RenderWindow& window, sf::Color colour)
{
	for (sf::Vector2i& i : getSnakeSegments())
	{
		sf::RectangleShape snakeBody({ 10, 10 });
		snakeBody.setOutlineThickness(0.5f);
		snakeBody.setOutlineColor(sf::Color::Black);
		snakeBody.setFillColor(i == getSnakeSegments()[0] ? sf::Color::Green : colour);
		snakeBody.setPosition((sf::Vector2f)i);
		window.draw(snakeBody);
	}
}
