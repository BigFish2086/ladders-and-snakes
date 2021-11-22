#pragma once

#include "Card.h"

class CardFour : public Card
{

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // Applies the effect of Cardfour on the passed Player
													  //  by moving the player to the start of the next snake 
													 //   if no snakes ahead do no thing

	virtual void Save(ofstream& OutFile, int type) override;

	virtual void Read(ifstream& Infile) override;

	virtual CardFour* Clone() const override;

	virtual ~CardFour(); // A Virtual Destructor
};

