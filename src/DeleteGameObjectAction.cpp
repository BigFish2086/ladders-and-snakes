#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "CellPosition.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on a cell to delete its object ...");
	position = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();            //get grid
	pGrid->RemoveObjectFromCell(position);       //remove game object from the clicked cell ->(deletegameobj)
	pGrid->SetClipboard(NULL);
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}
