#pragma once

#include "Card.h"

class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardSeven* Clone() const override;

	virtual ~CardSeven(); // A Virtual Destructor
};

