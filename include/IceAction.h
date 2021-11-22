#pragma once
#include "Grid.h"

class IceAction
{
	int victimNum;
public:
	IceAction();

	void ReadActionParameters(Grid* pGrid);

	bool Execute(Grid* pGrid);

	~IceAction();
};

