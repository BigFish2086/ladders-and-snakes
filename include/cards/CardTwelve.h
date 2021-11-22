#pragma once

#include "Station.h"
#include "Player.h"

class CardTwelve : public Station
{
	static double price_12, fees_12;
	static Player* owner_12;
	static int countMe_12;

public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static void setOwner(Player* p);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardTwelve* Clone() const override;

	virtual ~CardTwelve(); // A Virtual Destructor
};

