#include "Button.h"

Button::Button()
{

}

Button::Button(sf::VideoMode screenSize, std::string textString, int characterSize, sf::Font& font, sf::Color colour)
{
	buttonRect.setSize(sf::Vector2f(300, 100));
	buttonRect.setFillColor(sf::Color::Blue);
	buttonRect.setOrigin(buttonRect.getLocalBounds().width / 2, buttonRect.getLocalBounds().height / 2);

	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(characterSize);
	text.setFillColor(colour);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

Button::~Button() 
{

}

void Button::PositionButton(sf::Vector2f position)
{
	buttonRect.setPosition(position);
	text.setPosition(position);
}

void Button::DrawButton(sf::RenderWindow& window)
{
	window.draw(buttonRect);
	window.draw(text);
}
