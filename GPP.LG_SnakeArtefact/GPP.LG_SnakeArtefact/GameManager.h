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

	sf::Font font;
	sf::VideoMode desktopResolution;
	MainMenu mainMenu;
};

