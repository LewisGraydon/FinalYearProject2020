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
	setActive(true);

	//rectShape.setOrigin()
	int playableWidth = screenSize.width - 100;
	int playableHeight = screenSize.height - 100;

	// I used to be doing this, this may not be the optimal solution.
	//pickupPosition.y = (originY + 30) + rand() % (foregroundHeight - 90);


	setPosition(screenSize.width - (screenSize.width - 100), screenSize.height - (screenSize.height - 100));
	
	// temp.
	sf::Vector2f bounds = sf::Vector2f(screenSize.width - 100.0f, screenSize.height - 100.0f);

	for (sf::Vector2i& i : snake.getSnakeSegments())
	{
		while (position == i)
		{
			//setPosition()
		}
	}

	rectShape.setFillColor(sf::Color::Red);
	rectShape.setPosition((sf::Vector2f)position);
}
