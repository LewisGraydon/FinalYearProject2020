#pragma once
#include <SFML/Graphics.hpp>
#include "BaseSnakeClass.h"
#include "AISnake.h"
#include "PlayerSnake.h"
#include "Food.h"

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
	void CollisionDetection(BaseSnakeClass& snake);

private:

	sf::RectangleShape rectShape;
	sf::RectangleShape separatorRect;
	sf::Text helpText;
	sf::Text scoreText;
	BaseSnakeClass* snakeCharacter = nullptr;
	Food* foodObject = nullptr;
	bool playerControl;

	//Game world has snakes?

	// We want one snake reference, though if the AI controls it then the snake will be an AISnake and a PlayerSnake if player controlled.
};

