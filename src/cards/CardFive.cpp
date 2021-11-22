#include "CardFive.h"

#include <iostream>
#include <fstream>

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("New CardFive: Move again");
	pIn->GetPointClicked(x, y);
	pPlayer->Move(pGrid,pPlayer->GetJustRolledDiceNum());
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void CardFive::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		OutFile << "\n";
	}
}

void CardFive::Read(ifstream& Infile)
{
}

CardFive* CardFive::Clone() const
{
	return new CardFive(*this);
}

CardFive::~CardFive()
{
}
