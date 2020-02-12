#pragma once
#include <SFML/Graphics.hpp>

class GameWorld
{
public:

	GameWorld(sf::Font& font, sf::VideoMode screenSize);
	~GameWorld();

	void DrawGameWorld(sf::RenderWindow& window);

private:

	sf::RectangleShape rectShape;
	sf::Text helpText;
	sf::Text scoreText;
};

