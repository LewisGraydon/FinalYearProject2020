#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameWorld.h"

class GameManager
{
public:

	enum EGameState
	{
		eMainMenu,
		eNormalPlayMode,
		eAIPlayMode
	};

	GameManager(sf::VideoMode screenSize);
	~GameManager();

	void SetupMainMenu();
	void SetupGameWorld(bool playerControlled);

	void DrawMainMenu(sf::RenderWindow& window);
	void DrawGameWorld(sf::RenderWindow& window);

	MainMenu getMainMenu() { return *mainMenu; }

	sf::Font font;
	sf::VideoMode desktopResolution;
	EGameState gameState;

private:

	MainMenu* mainMenu;
	GameWorld* gameWorld;
};

