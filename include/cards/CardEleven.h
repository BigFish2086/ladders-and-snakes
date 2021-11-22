#pragma once

#include "Station.h"
#include "Player.h"

class CardEleven : public Station
{
	static double price_11, fees_11;
	static int countMe_11;
	static Player* owner_11;

public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static void setOwner(Player* p);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardEleven* Clone() const override;

	virtual ~CardEleven(); // A Virtual Destructor
};

