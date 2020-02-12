#include "GameWorld.h"

GameWorld::GameWorld(sf::Font& font,  sf::VideoMode screenSize)
{
	rectShape.setSize(sf::Vector2f(screenSize.width - 100.0f, screenSize.height - 100.0f));
	rectShape.setFillColor(sf::Color::Blue);
	rectShape.setOrigin(rectShape.getLocalBounds().width / 2, rectShape.getLocalBounds().height / 2);
	rectShape.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 2.0f));

	scoreText.setFont(font);
	scoreText.setString("0");
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	scoreText.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 10.0f));

	helpText.setFont(font);
	helpText.setString("Press Esc for main menu");
	helpText.setCharacterSize(20);
	helpText.setFillColor(sf::Color::White);
	helpText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	helpText.setPosition(sf::Vector2f(screenSize.width / 16.0f, screenSize.height / 10.0f));
}

GameWorld::~GameWorld()
{

}

void GameWorld::DrawGameWorld(sf::RenderWindow& window)
{
	window.draw(rectShape);
	window.draw(scoreText);
	window.draw(helpText);
}
