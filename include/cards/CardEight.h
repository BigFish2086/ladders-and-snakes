#pragma once

#include "Card.h"

class CardEight : public Card
{

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardEight* Clone() const override;

	virtual ~CardEight(); // A Virtual Destructor
};

