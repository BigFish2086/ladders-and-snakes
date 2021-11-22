#pragma once

#include "Action.h"

class SaveAction : public Action
{
	string fileName;
public:

	SaveAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell

	void Save(ofstream& outFile,Grid* pGrid);

	virtual ~SaveAction(); // Virtual Destructor

};

