#pragma once

#include "Station.h"
#include "Player.h"

class CardTen : public Station
{
	static double price_10, fees_10;
	static Player* owner_10;
	static int countMe_10;

public:
	CardTen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static void setOwner(Player* p);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardTen* Clone() const override;

	virtual ~CardTen(); // A Virtual Destructor
};

