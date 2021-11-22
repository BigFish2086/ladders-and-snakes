#pragma once

#include "Station.h"
#include "Player.h"

class CardFourteen : public Station
{
	static double price_14, fees_14;
	static Player* owner_14;
	static int countMe_14;

public:
	CardFourteen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static void setOwner(Player* p);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardFourteen* Clone() const override;

	virtual ~CardFourteen(); // A Virtual Destructor
};

