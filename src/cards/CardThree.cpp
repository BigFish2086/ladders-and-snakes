#include "CardThree.h"
#include "Ladder.h"

#include <iostream>
#include <fstream>
//constructor
CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	int jump = 0;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("New CardThree: Moving to start of next ladder");
	pIn->GetPointClicked(x,y);
	Ladder* nextLadder = pGrid->GetNextLadder(this->GetPosition());

	//check if there is any next ladder or not  
	//if there is jump to it ,  if not do nothing
    //jump hya el hta aly hantha mn el cell bta3t el card l next ladder = cell bta3t el ladder-cell aly ana 3laha
	if (nextLadder) {
		jump = nextLadder->GetPosition().GetCellNum() - this->GetPosition().GetCellNum();
		pPlayer->Move(pGrid,jump);                    //move the player
		pIn->GetPointClicked(x, y);
	}
	else {
		pOut->PrintMessage("There's no ladders ahead.Click to continue....");
		pIn->GetPointClicked(x, y);
	}
	pOut->ClearStatusBar();
}
 //saving cardthree
void CardThree::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		OutFile << "\n";
	}
}

void CardThree::Read(ifstream& Infile)
{
}

CardThree* CardThree::Clone() const
{
	return new CardThree(*this);
}

CardThree::~CardThree()
{
}
