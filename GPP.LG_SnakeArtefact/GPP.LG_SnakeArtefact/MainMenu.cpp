#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::MainMenu(sf::Font& font, sf::VideoMode screenSize)
{
	titleText.setFont(font);
	titleText.setString("Snake");
	titleText.setCharacterSize(128);
	titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
	titleText.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 10.0f));

	menuButtons[0] = new Button(screenSize, "Play", 48, font);
	menuButtons[1] = new Button(screenSize, "AI Play", 48, font);
	menuButtons[2] = new Button(screenSize, "Quit Game", 48, font);

	// origin is top left
	menuButtons[0]->PositionButton(sf::Vector2f(screenSize.width / 2.0f, screenSize.height - screenSize.height / (MaxNumItems + 4.0f) * 3.0f));
	menuButtons[1]->PositionButton(sf::Vector2f(screenSize.width / 2.0f, screenSize.height - screenSize.height / (MaxNumItems + 4.0f) * 2.0f));
	menuButtons[2]->PositionButton(sf::Vector2f(screenSize.width / 2.0f, screenSize.height - screenSize.height / (MaxNumItems + 4.0f) * 1.0f));
}

MainMenu::~MainMenu()
{
	 
}

void MainMenu::DrawMenu(sf::RenderWindow& window)
{
	window.draw(titleText);

	for (int i = 0; i < MaxNumItems; i++)
	{
		menuButtons[i]->DrawButton(window);
	}
}
