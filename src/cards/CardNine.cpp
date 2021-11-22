#include "CardNine.h"

#include <iostream>
#include <fstream>

CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardNine: Click on a cell so the player will go to when reaching me...");
	cellToReach = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	int jump = 0;
	Card::Apply(pGrid,pPlayer);
	if (cellToReach.IsValidCell()) {
		jump = cellToReach.GetCellNum() - pPlayer->GetCell()->GetCellPosition().GetCellNum();
		pPlayer->Move(pGrid,jump);
	}
}

void CardNine::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string reachCell = to_string(cellToReach.GetCellNum());
		OutFile << reachCell + "\n";
	}
}

void CardNine::Read(ifstream& Infile)
{
}

CardNine* CardNine::Clone() const
{
	return new CardNine(*this);
}

CardNine::~CardNine()
{
}
