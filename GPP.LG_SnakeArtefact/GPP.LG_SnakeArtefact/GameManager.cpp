#include "GameManager.h"

GameManager::GameManager(sf::VideoMode screenSize) : desktopResolution(screenSize)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		printf("Bad");
	}

	SetupMainMenu();
}

GameManager::~GameManager()
{
}

void GameManager::SetupMainMenu()
{
	if (mainMenu == nullptr)
	{
		mainMenu = new MainMenu(font, desktopResolution);
	}

	gameState = EGameState::eMainMenu;
}

void GameManager::SetupGameWorld(bool playerControlled)
{
	if (gameWorld == nullptr)
	{
		gameWorld = new GameWorld(font, desktopResolution);
	}
	gameWorld->SetPlayerControl(playerControlled);
	gameWorld->InitialiseGameWorld(desktopResolution);

	switch (playerControlled)
	{
	case true:
		gameState = EGameState::eNormalPlayMode;
		break;

	case false:
		gameState = EGameState::eAIPlayMode;
		break;
	}
}

void GameManager::DrawMainMenu(sf::RenderWindow& window)
{
	mainMenu->DrawMenu(window);
}

void GameManager::DrawGameWorld(sf::RenderWindow& window)
{
	gameWorld->DrawGameWorld(window);
}
