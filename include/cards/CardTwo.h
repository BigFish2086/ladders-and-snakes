#pragma once

#include "Card.h"

class CardTwo : public Card
{
	int walletAmount; // the wallet value to increase from the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by increasing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardTwo* Clone() const override;

	virtual ~CardTwo(); // A Virtual Destructor
};

