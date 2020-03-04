#include "ReinforcementLearning.h"

ReinforcementLearning::ReinforcementLearning()
{
	srand((unsigned)time(0));

	for (int i = 0; i <= (NUMBER_OF_STATES - 1); i++) 
	{
		for (int j = 0; j <= (NUMBER_OF_ACTIONS - 1); j++) 
		{
			QTable[i][j] = 0;
		} 
	}
}

ReinforcementLearning::~ReinforcementLearning()
{
}

void ReinforcementLearning::Episode(int initialState)
{
	currentState = initialState;
	do
	{
		ChooseAction();
	} 
	while (currentState == 5);

	for (int i = 0; i < NUMBER_OF_STATES; i++)
	{
		ChooseAction();
	}
}

void ReinforcementLearning::ChooseAction()
{
	int potentialAction;
	potentialAction = GetRandomAction(NUMBER_OF_ACTIONS, 0);

	if (R[currentState][potentialAction] >= 0)
	{
		QTable[currentState][potentialAction] = Reward(potentialAction);
		currentState = potentialAction;
	}
}

int ReinforcementLearning::GetRandomAction(int upperBound, int lowerBound)
{
	int action;
	bool isChoiceValid = false;
	int range = (upperBound - lowerBound) + 1;

	do
	{
		action = lowerBound + int(range * rand() / (RAND_MAX + 1.0));
		if (R[currentState][action] >= -1)
		{
			isChoiceValid = true;
		}
	} 
	while (isChoiceValid == false);

	return action;
}

int ReinforcementLearning::Maximum(int state, bool returnIndexOnly)
{
	
}

int ReinforcementLearning::Reward(int action)
{
	
}
