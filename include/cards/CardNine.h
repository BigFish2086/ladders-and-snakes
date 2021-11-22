#pragma once

#include "Card.h"
#include "CellPosition.h"

class CardNine : public Card
{
	CellPosition cellToReach;

public:
	CardNine(const CellPosition& pos); 

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardNine* Clone() const override;

	virtual ~CardNine(); // A Virtual Destructor
};

