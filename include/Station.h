#pragma once

#include "Card.h"
#include "Player.h"

class Station : public Card
{
	double fees, price;
public:
	Station(const CellPosition& pos); // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer, Player*& owner,double myPrice,double myFees);
	double GetPrice() const;
	double GetFees() const;
	virtual ~Station(); // A Virtual Destructor
};

