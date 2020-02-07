#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

class GameManager
{
public:

	GameManager(sf::VideoMode screenSize);
	~GameManager();

	void SetupMainMenu();
	bool SetupAIPlayer();
	bool SetupPlayer();

	void DrawMainMenu(sf::RenderWindow& window);

	MainMenu getMainMenu() { return *mainMenu; }

	sf::Font font;
	sf::VideoMode desktopResolution;

private:

	MainMenu* mainMenu;
};

