#include "Snake.h"

#include <iostream>
#include <fstream>

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}


void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}
void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a snake. Click to continue ...");
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

void Snake::Save(ofstream& OutFile, int type)
{
	if (type == 1) {
		string startPosition = to_string(GetPosition().GetCellNum());
		string endPosition = to_string(GetEndPosition().GetCellNum());
		OutFile << startPosition + " " + endPosition + "\n";
	}
}

void Snake::Load(ifstream& Infile, Grid* pGrid)
{
	int numberOFSnakes;
	Infile >> numberOFSnakes;
	for (int i = 0; i < numberOFSnakes; i++) {
		this->Read(Infile);
		if (GetPosition().IsValidCell() && GetEndPosition().IsValidCell()) {
			Snake* pSnake = new Snake(GetPosition(), GetEndPosition());
			bool added = pGrid->AddObjectToCell(pSnake);
			if (!added)
			{
				delete pSnake;
			}
		}
	}
}

void Snake::Read(ifstream& Infile)
{
	int start;
	int end;
	Infile >> start >> end;
	CellPosition startPos(start);
	SetPosition(startPos);
	CellPosition endPos(end);
	endCellPos = endPos;
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
	int start = GetEndPosition().GetCellNum();
	int end = GetPosition().GetCellNum();
	if (!overLapped) {
		for (int i = start; i <= end; i++) {
			UI.UsedCells[i] = 0;
		}
	}
}
