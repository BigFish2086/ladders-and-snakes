#pragma once
#include "Action.h"
class EditCardAction:public Action
{
		int cardNumber;          
	CellPosition* cardPosition;
	Cell*cell;
	Card *card;
public:
	EditCardAction(ApplicationManager *pApp);
	void ReadActionParameters();     
	virtual ~EditCardAction();
virtual void Execute();
};

