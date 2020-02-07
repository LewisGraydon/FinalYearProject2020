#include "GameWorld.h"

GameWorld::GameWorld(sf::VideoMode screenSize)
{
	rectShape.setSize(sf::Vector2f(screenSize.width - 100.0f, screenSize.height - 100.0f));
	rectShape.setFillColor(sf::Color::Blue);
	rectShape.setOrigin(rectShape.getLocalBounds().width / 2, rectShape.getLocalBounds().height / 2);
	rectShape.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 2.0f));
}

GameWorld::~GameWorld()
{

}

void GameWorld::DrawGameWorld(sf::RenderWindow& window)
{
	window.draw(rectShape);
}
