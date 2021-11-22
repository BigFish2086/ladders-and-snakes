#pragma once

#include"Action.h"

class CardCopyAction : public Action
{
	CellPosition cardPosition;
	Card* myCard;

public:
	CardCopyAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); 

	virtual void Execute(); 

	virtual ~CardCopyAction();

};

