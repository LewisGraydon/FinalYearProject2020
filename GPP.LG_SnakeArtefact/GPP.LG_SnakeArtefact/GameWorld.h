#pragma once
#include <SFML/Graphics.hpp>

class GameWorld
{
public:

	GameWorld(sf::VideoMode screenSize);
	~GameWorld();

	void DrawGameWorld(sf::RenderWindow& window);

private:

	sf::RectangleShape rectShape;
};

