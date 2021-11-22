#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include "CellPosition.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (endPos.HCell() != startPos.HCell() || endPos.GetCellNum() >= startPos.GetCellNum()) {
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
	}
	// Clear messages
	pOut->ClearStatusBar();
}
// Execute the action
void AddSnakeAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (startPos.IsValidCell() && endPos.IsValidCell()) {
		Snake* pSnake = new Snake(startPos, endPos);       // Create a snake object with the parameters read from the user
		bool added = pGrid->AddObjectToCell(pSnake);
		// if the GameObject cannot be added
		if (!added)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pSnake;
		}
	}
	else {
		pGrid->PrintErrorMessage("Invalid Parameters ....");
	}
	
}
AddSnakeAction::~AddSnakeAction()
{
}