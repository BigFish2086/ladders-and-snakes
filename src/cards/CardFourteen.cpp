#include "CardFourteen.h"
#include <locale>

#include <iostream>
#include <fstream>

double CardFourteen::price_14 = 0;
double CardFourteen::fees_14 = 0;
int CardFourteen::countMe_14 = 0;
Player* CardFourteen::owner_14 = NULL;

CardFourteen::CardFourteen(const CellPosition& pos) : Station(pos)
{
	cardNumber = 14;
}

void CardFourteen::ReadCardParameters(Grid* pGrid)
{
	if (countMe_14 == 0 || getEditAction()) {
		Station::ReadCardParameters(pGrid);
		price_14 = GetPrice();
		fees_14 = GetFees();
	}
	if (!getEditAction())
		countMe_14++;
}

void CardFourteen::Apply(Grid* pGrid, Player* pPlayer)
{
	Station::Apply(pGrid, pPlayer, owner_14, price_14, fees_14);
}

void CardFourteen::setOwner(Player* p)
{
	CardFourteen::owner_14 = p;
}

void CardFourteen::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string price = to_string(price_14);
		string fees = to_string(fees_14);
		string countMe = to_string(countMe_14);
		Card::Save(OutFile, type);
		OutFile << price + " " + fees + " " + countMe + "\n";
	}
}

void CardFourteen::Read(ifstream& Infile)
{
	Infile >> this->price_14;
	Infile >> this->fees_14;
	Infile >> this->countMe_14;
}

CardFourteen* CardFourteen::Clone() const
{
	countMe_14++;
	return new CardFourteen(*this);
}

CardFourteen::~CardFourteen()
{
	countMe_14--;
	if (countMe_14 == 0) {
		owner_14 = NULL;
	}
}
