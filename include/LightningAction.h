#pragma once
#include "Grid.h"

class LigthningAction
{
public:
	LigthningAction();

	 void ReadActionParameters(Grid* pGrid);

	 bool Execute(Grid* pGrid);

	~LigthningAction();
};

