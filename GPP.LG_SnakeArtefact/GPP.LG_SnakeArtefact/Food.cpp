#include "Food.h"
#include <random>

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

void Food::spawnFood(sf::Vector2i minGameBounds, sf::Vector2i maxGameBounds, BaseSnakeClass& snake)
{
	scoreAmount = 1;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(minGameBounds.y, maxGameBounds.y);

	// Randomly assign an x and y position for the food to spawn in that's a multiple of 10 within the bounds.
	position.x = minGameBounds.x + (((uni(rng) / 10) * 10) % (int)(maxGameBounds.x - 10 - minGameBounds.x));
	position.y = minGameBounds.y + (((uni(rng) / 10) * 10) % (int)(maxGameBounds.y - 10 - minGameBounds.y));

	// Check if the food would spawn in a snake segment, and if it does then generate a new position until it is no longer in the snake segment.
	for (sf::Vector2i& i : snake.getSnakeSegments())
	{
		while (position == i)
		{
			position.x = minGameBounds.x + (((uni(rng) / 10) * 10) % (int)(maxGameBounds.x - 10 - minGameBounds.x));
			position.y = minGameBounds.y + (((uni(rng) / 10) * 10) % (int)(maxGameBounds.y - 10- minGameBounds.y));
		}
	}

	rectShape.setFillColor(sf::Color::Magenta);
	rectShape.setOutlineThickness(1.0f);
	rectShape.setOutlineColor(sf::Color::Black);
	rectShape.setPosition((sf::Vector2f)position);

	setActive(true);
}
