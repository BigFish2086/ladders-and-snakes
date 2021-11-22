#include "CardTwelve.h"
#include <locale>

#include <iostream>
#include <fstream>

double CardTwelve::price_12 = 0;
double CardTwelve::fees_12 = 0;
int CardTwelve::countMe_12 = 0;
Player* CardTwelve::owner_12 = NULL;

CardTwelve::CardTwelve(const CellPosition& pos) : Station(pos)
{
	cardNumber = 12;
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	if (countMe_12 == 0 || getEditAction()) {
		Station::ReadCardParameters(pGrid);
		price_12 = GetPrice();
		fees_12 = GetFees();
	}
	if (!getEditAction())
		countMe_12++;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Station::Apply(pGrid, pPlayer, owner_12, price_12, fees_12);
}

void CardTwelve::setOwner(Player* p)
{
	CardTwelve::owner_12 = p;
}

void CardTwelve::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string price = to_string(price_12);
		string fees = to_string(fees_12);
		string countMe = to_string(countMe_12);
		Card::Save(OutFile,type);
		OutFile << price + " " + fees + " " + countMe + "\n";
	}
}

void CardTwelve::Read(ifstream& Infile)
{
	Infile >> this->price_12;
	Infile >> this->fees_12;
	Infile >> this->countMe_12;
}

CardTwelve* CardTwelve::Clone() const
{
	countMe_12++;
	return new CardTwelve(*this);
}

CardTwelve::~CardTwelve()
{
	countMe_12--;
	if (countMe_12 == 0) {
		owner_12 = NULL;
	}
}
