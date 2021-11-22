#include "CardSeven.h"

#include <iostream>
#include <fstream>

CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("New CardSeven: Roll Dice Again");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void CardSeven::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		OutFile << "\n";
	}
}

void CardSeven::Read(ifstream& Infile)
{
}

CardSeven* CardSeven::Clone() const
{
	return new CardSeven(*this);
}

CardSeven::~CardSeven()
{
}
