#include "GameWorld.h"
#include <sstream>

GameWorld::GameWorld(sf::Font& font,  sf::VideoMode screenSize) : sizeOfScreen(screenSize)
{
	// Set up the background.
	rectShape.setSize(sf::Vector2f(/*screenSize.width - 1620.0f*/ 400.0f, /*screenSize.height - 900.0f*/ 400.0f));
	rectShape.setFillColor(sf::Color::Blue);
	rectShape.setOrigin(rectShape.getLocalBounds().width / 2, rectShape.getLocalBounds().height / 2);
	rectShape.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 2.0f));

	// Set up the bar that will separate the playable area from the score and help text.
	separatorRect.setSize({ screenSize.width - 100.0f, 50.0f });
	separatorRect.setFillColor(sf::Color::Black);
	separatorRect.setOrigin(separatorRect.getLocalBounds().width / 2, 0);
	separatorRect.setPosition({ screenSize.width / 2.0f, screenSize.height / 6.0f });

	// Set up the score text.
	scoreText.setFont(font);
	scoreText.setString("0");
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	scoreText.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 10.0f));

	// Set up the help text, to inform the user how to exit to the main menu.
	helpText.setFont(font);
	helpText.setString("Press Esc for main menu");
	helpText.setCharacterSize(20);
	helpText.setFillColor(sf::Color::White);
	helpText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	helpText.setPosition(sf::Vector2f(screenSize.width / 4.0f, screenSize.height / 10.0f));

	// Set up the end game text.
	endGameText.setFont(font);
	endGameText.setString("");
	endGameText.setCharacterSize(40);
	endGameText.setFillColor(sf::Color::White);
	endGameText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	endGameText.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 2.0f));

	minGameBounds = { (int)(screenSize.width / 2 - (rectShape.getSize().x / 2)), (int)(screenSize.height / 2 - (rectShape.getSize().y / 2)) };
	maxGameBounds = { (int)(screenSize.width / 2 + (rectShape.getSize().x / 2)), (int)(screenSize.height / 2 + (rectShape.getSize().y / 2)) };
}

GameWorld::~GameWorld()
{

}

void GameWorld::InitialiseGameWorld(sf::VideoMode screenSize)
{
	// If we selected the normal play mode we will create a snake that can be controlled by the player, otherwise we will create an AI snake.
	if (playerControl)
	{
		snakeCharacter = new PlayerSnake(screenSize, minGameBounds, maxGameBounds);
	}
	else
	{
		snakeCharacter = new AISnake(screenSize);
	}

	// Spawn a piece of food in the game world.
	foodObject = new Food();
	foodObject->spawnFood(minGameBounds, maxGameBounds, *snakeCharacter);
}

void GameWorld::DrawGameWorld(sf::RenderWindow& window)
{
	window.draw(rectShape);
	window.draw(separatorRect);
	UpdateScore(*snakeCharacter);
	window.draw(scoreText);
	window.draw(helpText);
	snakeCharacter->drawSnake(window, sf::Color::Green);
	
	// Draw the foodObject if it's active.
	if (foodObject->getActive())
	{
		foodObject->drawFood(window);
	}

	// If the size of the snake is the same as the amount of squares in the playable space, then they win.
	if (snakeCharacter->getSnakeSegments().size() == (((size_t) maxGameBounds.x - (size_t) minGameBounds.x) * ((size_t) maxGameBounds.y - (size_t) minGameBounds.y)))
	{
		snakeCharacter->setActive(false);
		endGameText.setString("Victory!");
		endGameText.setOrigin(endGameText.getLocalBounds().width / 2, endGameText.getLocalBounds().height / 2);
	}

	// Show the end game text if the snake is no longer active.
	if (!snakeCharacter->getActive())
	{
		window.draw(endGameText);
	}
}

void GameWorld::UpdateScore(BaseSnakeClass& snake)
{
	// Update the score and modify the origin to accommodate the length of the scoreText increasing.
	std::ostringstream score;
	score << "Score: " << snake.getScore();
	scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	scoreText.setString(score.str());
}

void GameWorld::Update(sf::Event& event, sf::RenderWindow& window)
{
	// Update the snake only if it is active.
	if (snakeCharacter->getActive())
	{
		snakeCharacter->Update(event, window, sizeOfScreen);
		snakeCharacter->moveSnake();
		CollisionDetection(*snakeCharacter, sizeOfScreen);		
	}
}

void GameWorld::CollisionDetection(BaseSnakeClass& snake, sf::VideoMode screenSize)
{
	// Check for collision between the head of the snake and itself.
	for (int i = 1; i < snake.getSnakeSegments().size(); i++)
	{
		sf::Vector2i snakeOffset = snake.getSnakeSegments()[0] - snake.getSnakeSegments()[i];
		if ((snakeOffset.x * snakeOffset.x) + (snakeOffset.y * snakeOffset.y) < (snake.getLengthOfASide() * snake.getLengthOfASide()))
		{
			snake.setActive(false);
			endGameText.setString("Game Over!");
			endGameText.setOrigin(endGameText.getLocalBounds().width / 2, endGameText.getLocalBounds().height / 2);
		}	
	}

	// Check for collision between the snake and the four boundaries of the game world. 
	if (snake.getSnakeSegments()[0].x < minGameBounds.x || snake.getSnakeSegments()[0].x >= maxGameBounds.x || 
		snake.getSnakeSegments()[0].y >= maxGameBounds.y || snake.getSnakeSegments()[0].y < minGameBounds.y) // Has to be >= since segment origin top left.
	{
		snake.setActive(false);
		endGameText.setString("Game Over!");
		endGameText.setOrigin(endGameText.getLocalBounds().width / 2, endGameText.getLocalBounds().height / 2);
	}

	// Check for collision between the snake head and the foodObject, but only if the food is active.
	if (foodObject->getActive())
	{
		sf::Vector2i foodOffset = snake.getSnakeSegments()[0] - foodObject->getPosition();
		if ((foodOffset.x * foodOffset.x) + (foodOffset.y * foodOffset.y) < (snake.getLengthOfASide() * snake.getLengthOfASide()))
		{
			snake.getSnakeSegments().push_back({ -100,-100 });
			snake.setScore(foodObject->getScoreAmount());
			foodObject->setActive(false);
			foodObject->spawnFood(minGameBounds, maxGameBounds, snake);
		}
	}
}
