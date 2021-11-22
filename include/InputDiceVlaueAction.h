#pragma once

#include "Action.h"

class InputDiceVlaueAction : public Action
{
	int diceValue;

public:

	InputDiceVlaueAction(ApplicationManager* pApp);

	void ReadActionParameters();
	
	void Execute();
	
	~InputDiceVlaueAction();
};

