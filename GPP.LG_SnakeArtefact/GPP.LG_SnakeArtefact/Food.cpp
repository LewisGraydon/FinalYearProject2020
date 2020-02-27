#include "Food.h"
#include <random>

#define xBounds 350

Food::Food()
{

}

Food::~Food()
{

}

void Food::drawFood(sf::RenderWindow& window)
{
	window.draw(rectShape);
}

void Food::spawnFood(sf::VideoMode screenSize, BaseSnakeClass& snake)
{
	scoreAmount = 1;

	// Get the bounds of the play area.
	int maxY = (screenSize.height - 60);
	int minY = screenSize.height - (screenSize.height - 50 - (screenSize.height / 6));
	int maxX = screenSize.width - (xBounds + 10);
	int minX = xBounds;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(minY, maxY);

	// Randomly assign an x and y position for the food to spawn in that's a multiple of 10 within the bounds.
	position.x = xBounds + (((uni(rng) / 10) * 10) % (int)((screenSize.width - 60) - xBounds));
	position.y = minY + (((uni(rng) / 10) * 10) % (int)(maxY - minY));
	
	// Check if the food would spawn in a snake segment, and if it does then generate a new position until it is no longer in the snake segment.
	for (sf::Vector2i& i : snake.getSnakeSegments())
	{
		while (position == i)
		{
			position.x = minX + (((uni(rng) / 10) * 10) % (int)(maxX - minX));
			position.y = minY + (((uni(rng) / 10) * 10) % (int)(maxY - minY));
		}
	}

	rectShape.setFillColor(sf::Color::Magenta);
	rectShape.setOutlineThickness(1.0f);
	rectShape.setOutlineColor(sf::Color::Black);
	rectShape.setPosition((sf::Vector2f)position);

	setActive(true);
}
