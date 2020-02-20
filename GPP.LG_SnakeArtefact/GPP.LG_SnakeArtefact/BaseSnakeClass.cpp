#include "BaseSnakeClass.h"

BaseSnakeClass::BaseSnakeClass(sf::VideoMode screenSize) : sizeOfScreen(screenSize)
{
	// Initially push back some segments to the vector to create the initial snake.
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2)); 
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2 - 10));
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2 - 20));
	snakeSegments->push_back(sf::Vector2i(screenSize.width / 2, screenSize.height / 2 - 30));
}

BaseSnakeClass::~BaseSnakeClass()
{
}

void BaseSnakeClass::moveSnake()
{
	sf::Vector2i temp;
	sf::Vector2i previousPosition(InvalidPosition, InvalidPosition);
	sf::Vector2i velocity(0,0);

	// Switch on the direction enum to determine the distance the head of the snake will move, at the start of the game the snake will not move as the direction will be eNone. 
	switch (direction)
	{
	case eNone:
		return;
		break;

	case eUp:
		velocity.x = 0;
		velocity.y = -10;
		break;

	case eDown:
		velocity.x = 0;
		velocity.y = 10;
		break;

	case eLeft:
		velocity.x = -10;
		velocity.y = 0;
		break;

	case eRight:
		velocity.x = 10;
		velocity.y = 0;
		break;

	default:
		break;
	}

	// Loop through each snake segment. If the segment is the head, we'll move it by the velocity, otherwise we will be setting the position of the segment to be the previous segment in the array.
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
			i = previousPosition;
			previousPosition = temp;
		}
	}
}

void BaseSnakeClass::drawSnake(sf::RenderWindow& window, sf::Color colour)
{
	// Loop through all the snake segments in the snake.
	for (sf::Vector2i& i : getSnakeSegments())
	{
		// Set up the snake body shape as well as it's outline colour / thickness.
		sf::RectangleShape snakeBody({ lengthOfASide, lengthOfASide });
		snakeBody.setOutlineThickness(1.0f);
		snakeBody.setOutlineColor(sf::Color::Black);

		// Set the colour of the snake to be whatever the colour variable is, unless it is the head where we'll use the colour red instead.
		snakeBody.setFillColor(i == getSnakeSegments()[0] ? sf::Color::Red : colour);
		snakeBody.setPosition((sf::Vector2f)i);
		window.draw(snakeBody);
	}
}


