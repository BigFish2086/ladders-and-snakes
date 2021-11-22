#pragma once
#include "Grid.h"

class FireAction
{
	int victimNum;
public:
	FireAction();

	void ReadActionParameters(Grid* pGrid);

	bool Execute(Grid* pGrid);

	~FireAction();
};

