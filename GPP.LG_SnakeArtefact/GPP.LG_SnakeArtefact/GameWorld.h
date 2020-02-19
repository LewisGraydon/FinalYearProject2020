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
	void CollisionDetection(BaseSnakeClass& snake, sf::VideoMode screenSize);

private:

	sf::RectangleShape rectShape;
	sf::RectangleShape separatorRect;
	sf::Text helpText;
	sf::Text scoreText;
	BaseSnakeClass* snakeCharacter = nullptr;
	Food* foodObject = nullptr;
	bool playerControl;

	// End Game Text. This will show either when the snake dies or when they win the game.
	sf::Text endGameText;
	sf::VideoMode sizeOfPlayableArea;
};

