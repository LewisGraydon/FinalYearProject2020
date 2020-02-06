#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:

	Button();
	Button(sf::VideoMode screenSize, std::string textString, int characterSize, sf::Font& font);
	~Button();

	void PositionButton(sf::Vector2f position);
	void DrawButton(sf::RenderWindow& window);

	sf::Text text;
	sf::RectangleShape buttonRect;
};

