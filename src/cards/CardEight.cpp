#include "CardEight.h"

#include <iostream>
#include <fstream>

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("New CardEight: Player p" + to_string(pPlayer->GetPlayerNumber()) +" won't roll dice next time..");
	pPlayer->SetMoveAction(false);
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	
}

void CardEight::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		OutFile << "\n";
	}
}

void CardEight::Read(ifstream& Infile)
{
}

CardEight* CardEight::Clone() const
{
	return new CardEight(*this);
}

CardEight::~CardEight()
{
}
