#pragma once

#include "Card.h"

class CardFive : public Card
{

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardFive* Clone() const override;

	virtual ~CardFive(); // A Virtual Destructor
};

