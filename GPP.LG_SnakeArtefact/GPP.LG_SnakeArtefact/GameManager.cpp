#include "GameManager.h"

GameManager::GameManager(sf::VideoMode screenSize) : desktopResolution(screenSize)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		printf("Bad");
	}
}

GameManager::~GameManager()
{
}

void GameManager::SetupMainMenu()
{
	mainMenu = MainMenu(font, desktopResolution);
}

bool GameManager::SetupAIPlayer()
{
	return true;
}

bool GameManager::SetupPlayer()
{
	return true;
}

void GameManager::DrawMainMenu(sf::RenderWindow& window)
{
	mainMenu.DrawMenu(window);
}
