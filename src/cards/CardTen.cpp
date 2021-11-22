#include "CardTen.h"
#include <locale>

#include <iostream>
#include <fstream>

double CardTen::price_10 = 0;
double CardTen::fees_10 = 0;
int CardTen::countMe_10 = 0;
Player* CardTen::owner_10 = NULL;

CardTen::CardTen(const CellPosition& pos) : Station(pos)
{
	cardNumber = 10;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	if (countMe_10 == 0 || getEditAction()) {
		Station::ReadCardParameters(pGrid);
		price_10 = GetPrice();
		fees_10 = GetFees();
	}
	if (!getEditAction())
		countMe_10++;
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Station::Apply(pGrid, pPlayer, owner_10, price_10, fees_10);
}

void CardTen::setOwner(Player* p)
{
	CardTen::owner_10 = p;
}

void CardTen::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string price = to_string(price_10);
		string fees = to_string(fees_10);
		string countMe = to_string(countMe_10);
		Card::Save(OutFile, type);
		OutFile << price + " " + fees + " " + countMe + " " + "\n";
	}
}

void CardTen::Read(ifstream& Infile)
{
	Infile >> this->price_10;
	Infile >> this->fees_10;
	Infile >> this->countMe_10;
}

CardTen* CardTen::Clone() const
{
	countMe_10++;
	return new CardTen(*this);
}

CardTen::~CardTen()
{
	countMe_10--;
	std::cout << "Card 10 deleted " << std::endl;
	if (countMe_10 == 0) {
		owner_10 = NULL;
	}
}
