#pragma once

#include "Action.h"

class LoadAction : public Action
{
	string fileName;
public:

	LoadAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell

	virtual ~LoadAction(); // Virtual Destructor

};

