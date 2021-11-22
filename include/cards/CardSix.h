#pragma once

#include "Card.h"

class CardSix : public Card
{

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardSix* Clone() const override;

	virtual ~CardSix(); // A Virtual Destructor
};

