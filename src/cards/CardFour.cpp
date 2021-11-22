#include "CardFour.h"
#include "Snake.h"

#include <iostream>
#include <fstream>

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	int jump = 0;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("New CardFour: Moving to start of next snake");
	pIn->GetPointClicked(x, y);
	Snake* nextSnake = pGrid->GetNextSnake(this->GetPosition());
	//check if there is any next snake or not  
//if there is jump to it ,  if not do nothing
//jump hya el hta aly hantha mn el cell bta3t el card l next snake = cell bta3t el ladder-cell aly ana 3laha
	if (nextSnake) {
		jump = nextSnake->GetPosition().GetCellNum() - this->GetPosition().GetCellNum();
		pPlayer->Move(pGrid, jump);        //move the player
		pIn->GetPointClicked(x, y);
	}
	else {
		pOut->PrintMessage("There's no snakes ahead.Click to continue....");
		pIn->GetPointClicked(x, y);
	}
	pOut->ClearStatusBar();
}
//saving cardfour
void CardFour::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		OutFile << "\n";
	}
}

void CardFour::Read(ifstream& Infile)
{
}

CardFour* CardFour::Clone() const
{
	return new CardFour(*this);
}

CardFour::~CardFour()
{
}
