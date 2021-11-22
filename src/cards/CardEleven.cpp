#include "CardEleven.h"
#include <locale>

#include <iostream>
#include <fstream>

double CardEleven::price_11 = 0;
double CardEleven::fees_11 = 0;
int CardEleven::countMe_11 = 0;
Player* CardEleven::owner_11 = NULL;

CardEleven::CardEleven(const CellPosition& pos) : Station(pos)
{
	cardNumber = 11;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (countMe_11 == 0 || getEditAction()) {
		Station::ReadCardParameters(pGrid);
		price_11 = GetPrice();
		fees_11 = GetFees();
	}
	if(!getEditAction())
		countMe_11++;
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Station::Apply(pGrid, pPlayer, owner_11,price_11,fees_11);
}

void CardEleven::setOwner(Player* p)
{
	CardEleven::owner_11 = p;
}

void CardEleven::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string price = to_string(price_11);
		string fees = to_string(fees_11);
		string countMe = to_string(countMe_11);
		Card::Save(OutFile, type);
		OutFile << price + " " + fees + " " + countMe + "\n";
	}
}

void CardEleven::Read(ifstream& Infile)
{
	Infile >> this->price_11;
	Infile >> this->fees_11;
	Infile >> this->countMe_11;
}

CardEleven* CardEleven::Clone() const
{
	countMe_11++;
	return new CardEleven(*this);
}

CardEleven::~CardEleven()
{
	countMe_11--;
	if (countMe_11 == 0) {
		owner_11 = NULL;
	}
}
