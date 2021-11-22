#pragma once

#include"Action.h"

class CardPasteAction : public Action
{
	CellPosition pastePosition;
	Card* oldCopy;
	Card* newCopy;

public:
	CardPasteAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CardPasteAction();

};

