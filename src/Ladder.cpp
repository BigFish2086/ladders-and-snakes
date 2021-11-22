#include "Ladder.h"

#include <iostream>
#include <fstream>


Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());                    
	
}

void Ladder::Save(ofstream& OutFile, int type)
{
	if (type == 0) {
		string startPosition = to_string(GetPosition().GetCellNum());
		string endPosition = to_string(GetEndPosition().GetCellNum());
		OutFile << startPosition + " " + endPosition + "\n";
	}
}

void Ladder::Load(ifstream& Infile, Grid* pGrid)
{
	int numberOFLadders;
	Infile >> numberOFLadders;
	for (int i = 0; i < numberOFLadders; i++) {
		this->Read(Infile);
		if (GetPosition().IsValidCell() && GetEndPosition().IsValidCell()) {
			Ladder* pLadder = new Ladder(GetPosition(), GetEndPosition());
			bool added = pGrid->AddObjectToCell(pLadder);
			if (!added)
			{
				delete pLadder;
			}
		}
	}
}

void Ladder::Read(ifstream& Infile)
{
	int start;
	int end;
	Infile >> start >> end;
	CellPosition startPos(start);
	SetPosition(startPos);
	CellPosition endPos(end);
	endCellPos = endPos;
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
	int start = GetPosition().GetCellNum();
	int end = GetEndPosition().GetCellNum();
	if (!overLapped) {
		for (int i = start; i <= end; i++) {
			UI.UsedCells[i] = 0;
		}
	}

}
