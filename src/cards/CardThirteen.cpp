#include "CardThirteen.h"
#include <locale>

#include <iostream>
#include <fstream>

double CardThirteen::price_13 = 0;
double CardThirteen::fees_13 = 0;
int CardThirteen::countMe_13 = 0;
Player* CardThirteen::owner_13 = NULL;

CardThirteen::CardThirteen(const CellPosition& pos) : Station(pos)
{
	cardNumber = 13;
}

void CardThirteen::ReadCardParameters(Grid* pGrid)
{
	if (countMe_13 == 0 || getEditAction()) {
		Station::ReadCardParameters(pGrid);
		price_13 = GetPrice();
		fees_13 = GetFees();
	}
	if (!getEditAction())
		countMe_13++;
}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
{
	Station::Apply(pGrid, pPlayer, owner_13, price_13, fees_13);
}

void CardThirteen::setOwner(Player* p)
{
	CardThirteen::owner_13 = p;
}

void CardThirteen::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string price = to_string(price_13);
		string fees = to_string(fees_13);
		string countMe = to_string(countMe_13);
		Card::Save(OutFile, type);
		OutFile << price + " " + fees + " " + countMe + "\n";
	}
}

void CardThirteen::Read(ifstream& Infile)
{
	Infile >> this->price_13;
	Infile >> this->fees_13;
	Infile >> this->countMe_13;
}

CardThirteen* CardThirteen::Clone() const
{
	countMe_13++;
	return new CardThirteen(*this);
}

CardThirteen::~CardThirteen()
{
	countMe_13--;
	if (countMe_13 == 0) {
		owner_13 = NULL;
	}
}
