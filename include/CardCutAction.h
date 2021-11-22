#pragma once

#include"Action.h"

class CardCutAction : public Action
{
	CellPosition cardPosition;
	Card* myCard;

public:
	CardCutAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CardCutAction();

};

