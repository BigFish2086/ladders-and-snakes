#pragma once

#include "Station.h"
#include "Player.h"

class CardThirteen : public Station
{
	static double price_13, fees_13;
	static Player* owner_13;
	static int countMe_13;

public:
	CardThirteen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static void setOwner(Player* p);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardThirteen* Clone() const override;

	virtual ~CardThirteen(); // A Virtual Destructor
};

