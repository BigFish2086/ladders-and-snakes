#include "CardOne.h"

#include <iostream>
#include <fstream>

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

void CardOne::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		Card::Save(OutFile, 2);
		string walletDec = to_string(walletAmount);
		OutFile << walletDec + "\n";
	}
}

void CardOne::Read(ifstream& Infile)
{
	Infile >> this->walletAmount;
}

CardOne* CardOne::Clone() const
{
	return new CardOne(*this);
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardOne: Enter its wallet amount : ");
	walletAmount = abs(pIn->GetInteger(pOut));
	if (walletAmount < 0)
	{
		pGrid->PrintErrorMessage("Error: Invalid Wallet Amount (Set to Zero) ! Click to continue ...");
		walletAmount = 0;
	}
	pOut->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
	//pGrid->UpdateInterface();
}
