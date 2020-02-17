#include "GameWorld.h"
#include <sstream>

GameWorld::GameWorld(sf::Font& font,  sf::VideoMode screenSize)
{
	rectShape.setSize(sf::Vector2f(screenSize.width - 100.0f, screenSize.height - 100.0f));
	rectShape.setFillColor(sf::Color::Blue);
	rectShape.setOrigin(rectShape.getLocalBounds().width / 2, rectShape.getLocalBounds().height / 2);
	rectShape.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 2.0f));

	separatorRect.setSize({ screenSize.width - 100.0f, 50.0f });
	separatorRect.setFillColor(sf::Color::Black);
	separatorRect.setOrigin(separatorRect.getLocalBounds().width / 2, 0);
	separatorRect.setPosition({ screenSize.width / 2.0f, screenSize.height / 6.0f });

	scoreText.setFont(font);
	scoreText.setString("0");
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	scoreText.setPosition(sf::Vector2f(screenSize.width / 2.0f, screenSize.height / 10.0f));

	helpText.setFont(font);
	helpText.setString("Press Esc for main menu");
	helpText.setCharacterSize(20);
	helpText.setFillColor(sf::Color::White);
	helpText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	helpText.setPosition(sf::Vector2f(screenSize.width / 16.0f, screenSize.height / 10.0f));
}

GameWorld::~GameWorld()
{

}

void GameWorld::InitialiseGameWorld(sf::VideoMode screenSize)
{
	if (playerControl)
	{
		snakeCharacter = new PlayerSnake(screenSize);
	}
	else
	{
		snakeCharacter = new AISnake(screenSize);
	}

	foodObject = new Food();
	foodObject->spawnFood(screenSize, *snakeCharacter);
}

void GameWorld::DrawGameWorld(sf::RenderWindow& window)
{
	window.draw(rectShape);
	window.draw(separatorRect);
	UpdateScore(*snakeCharacter);
	window.draw(scoreText);
	window.draw(helpText);
	snakeCharacter->drawSnake(window, sf::Color::Green);
	
	if (foodObject)
	{
		foodObject->drawFood(window);
	}
}

void GameWorld::UpdateScore(BaseSnakeClass& snake)
{
	std::ostringstream score;
	score << "Score: " << snake.getScore();
	scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	scoreText.setString(score.str());
}

void GameWorld::Update(sf::Event& event)
{
	snakeCharacter->Update(event);
	snakeCharacter->moveSnake();
	CollisionDetection(*snakeCharacter);
}

void GameWorld::CollisionDetection(BaseSnakeClass& snake)
{
	for (int i = 1; i < snake.getSnakeSegments().size(); i++)
	{
		sf::Vector2i snakeOffset = snake.getSnakeSegments()[0] - snake.getSnakeSegments()[i];
		if ((snakeOffset.x * snakeOffset.x) + (snakeOffset.y * snakeOffset.y) < (snake.getLengthOfASide() * snake.getLengthOfASide()))
		{
			// DEATH
		}	
	}

	if (foodObject)
	{
		sf::Vector2i foodOffset = snake.getSnakeSegments()[0] - foodObject->getPosition();
		if ((foodOffset.x * foodOffset.x) + (foodOffset.y * foodOffset.y) < (snake.getLengthOfASide() * snake.getLengthOfASide()))
		{
			snake.getSnakeSegments().push_back({ -100,-100 });
			delete foodObject;
			foodObject = nullptr;
		}
	}
}
