#pragma once
#include "Grid.h"

class PoisonAction
{
	int victimNum;
public:
	PoisonAction();

	void ReadActionParameters(Grid* pGrid);

	bool Execute(Grid* pGrid);

	~PoisonAction();
};

