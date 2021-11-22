#include "CardEditAction.h"

#include"Grid.h"
#include"Output.h"
#include"Input.h"
#include "Card.h"

CardEditAction::CardEditAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CardEditAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on a card to edit ....");
	cardPosition = pIn->GetCellClicked();                     //the cell chosen
	pOut->ClearStatusBar();
}
// Execute the action
void CardEditAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	myCard = pGrid->CheckForCards(cardPosition);                  
	if (myCard) {                                                //( check if this cell has card or not ) and return pointer on it if 
		myCard->setEditAction(true);                              //there a card on it    and null if there isnot
		myCard->ReadCardParameters(pGrid);
		myCard->setEditAction(false);
	}
	else {                                                           //if my card =null
		pGrid->PrintErrorMessage("This cell has no cards ..");
	}
	pOut->ClearStatusBar();
}

CardEditAction::~CardEditAction()
{
}
