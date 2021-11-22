#pragma once

#include "Card.h"

class CardThree : public Card
{

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // Applies the effect of Cardthere on the passed Player
													  //  by moving the player to the start of the next ladder 
													 //   if no ladders ahead do no thing

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardThree* Clone() const override;

	virtual ~CardThree(); // A Virtual Destructor
};

