#pragma once

#include "Action.h"

class DeleteGameObjectAction : public Action
{	

	CellPosition position; //Action Parameter

public:

	DeleteGameObjectAction(ApplicationManager *pApp); 

	virtual void ReadActionParameters(); 
	
	virtual void Execute(); 
	

	virtual ~DeleteGameObjectAction(); // Virtual Destructor

};

