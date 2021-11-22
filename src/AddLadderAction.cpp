#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "CellPosition.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (endPos.HCell() != startPos.HCell() || endPos.GetCellNum() <= startPos.GetCellNum()) {
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
	}
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	// Create a Ladder object with the parameters read from the user
	if (startPos.IsValidCell() && endPos.IsValidCell()) {
		Ladder* pLadder = new Ladder(startPos, endPos);
		// We get a pointer to the Grid from the ApplicationManager
	   // Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pLadder);
		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pLadder;
		}
	}
	else {
		pGrid->PrintErrorMessage("Invalid Parameters ....");
	}

	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
