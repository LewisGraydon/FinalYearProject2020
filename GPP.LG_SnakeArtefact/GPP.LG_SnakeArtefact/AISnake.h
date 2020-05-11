#pragma once
#include "BaseSnakeClass.h"

#include <fstream>
#include "ExternalSources/ALGLib-3.16.0/dataanalysis.h"
#include "ExternalSources/ALGLib-3.16.0/stdafx.h"

class AISnake : public BaseSnakeClass
{
public:
	AISnake(sf::VideoMode screenSize, sf::Vector2i minBounds, sf::Vector2i maxBounds);
	~AISnake();

	void Update(sf::Event& event, sf::RenderWindow& window, sf::VideoMode screenSize);

	void DetermineDirection(sf::RenderWindow& window, sf::VideoMode screenSize);

	float MakeAISmartAgain(float currentDirection);

private:

	sf::Vector2i minGameBounds = {};
	sf::Vector2i maxGameBounds = {};

	alglib::multilayerperceptron net;
	alglib::real_1d_array x;
	alglib::real_1d_array y = "[0]";
};

