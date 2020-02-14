#pragma once
#include <SFML/Graphics.hpp>
#include "BaseSnakeClass.h"
#include "AISnake.h"
#include "PlayerSnake.h"


class GameWorld
{
public:

	GameWorld(sf::Font& font, sf::VideoMode screenSize);
	~GameWorld();

	void InitialiseGameWorld(sf::VideoMode screenSize);
	void DrawGameWorld(sf::RenderWindow& window);
	void UpdateScore(BaseSnakeClass& snake);
	void SetPlayerControl(bool control) { playerControl = control; }
	void Update(sf::Event& event);


private:

	sf::RectangleShape rectShape;
	sf::Text helpText;
	sf::Text scoreText;
	BaseSnakeClass* snakeCharacter;
	bool playerControl;

	//Game world has snakes?

	// We want one snake reference, though if the AI controls it then the snake will be an AISnake and a PlayerSnake if player controlled.
};

