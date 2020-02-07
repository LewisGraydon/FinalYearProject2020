#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

#define MaxNumItems 3

class MainMenu
{
public:

	MainMenu();
	MainMenu(sf::Font& font, sf::VideoMode screenSize);
	~MainMenu();

	void DrawMenu(sf::RenderWindow& window);
	void NavigateUp();
	void NavigateDown();
	int getSelectedIndex() { return *selectedIndex; }

private:

	int *selectedIndex;
	sf::Text titleText;
	Button* menuButtons[MaxNumItems];
};

