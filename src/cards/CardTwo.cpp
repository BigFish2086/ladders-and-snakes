#include "CardTwo.h"

#include <iostream>
#include <fstream>

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardTWo: Enter its wallet amount : ");
	walletAmount = abs(pIn->GetInteger(pOut));
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
	//pGrid->UpdateInterface();
}

void CardTwo::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		string walletInc = to_string(walletAmount);
		OutFile << walletInc + "\n";
	}
}

void CardTwo::Read(ifstream& Infile)
{
	Infile >> this->walletAmount;
}

CardTwo* CardTwo::Clone() const
{
	return new CardTwo(*this);
}

CardTwo::~CardTwo()
{
}
