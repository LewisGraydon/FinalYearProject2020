#include "Food.h"

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
	scoreAmount = 100;
	
	//rectShape.setOrigin()
	int playableWidth = screenSize.width - 100;
	int playableHeight = screenSize.height - 100;

	// I used to be doing this, this may not be the optimal solution.
	//pickupPosition.y = (originY + 30) + rand() % (foregroundHeight - 90);

	float offset = (screenSize.height - 100.0f - (screenSize.height / 6.0f));

	setPosition(screenSize.width - (screenSize.width - 100.0f), screenSize.height - offset);
	
	// temp.
	sf::Vector2f bounds = sf::Vector2f(screenSize.width - 100.0f, offset);

	for (sf::Vector2i& i : snake.getSnakeSegments())
	{
		while (position == i)
		{
			//setPosition()
		}
	}

	rectShape.setFillColor(sf::Color::Magenta);
	rectShape.setOutlineThickness(1.0f);
	rectShape.setOutlineColor(sf::Color::Black);
	rectShape.setPosition((sf::Vector2f)position);
	
	setActive(true);
}
