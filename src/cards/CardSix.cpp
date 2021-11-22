#include "CardSix.h"

#include <iostream>
#include <fstream>

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("New CardSix: Move BackWord");
	pIn->GetPointClicked(x, y);
	pPlayer->Move(pGrid,-(pPlayer->GetJustRolledDiceNum()));
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void CardSix::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
	}
}

void CardSix::Read(ifstream& Infile)
{
}

CardSix* CardSix::Clone() const
{
	return new CardSix(*this);
}

CardSix::~CardSix()
{
}
