#pragma once

#include "Action.h"

class CardEditAction : public Action
{
	CellPosition cardPosition;
	Card* myCard;

public:
	CardEditAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();

	virtual ~CardEditAction();
	
};

