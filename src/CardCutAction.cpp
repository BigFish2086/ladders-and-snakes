#include "CardCutAction.h"

#include"Grid.h"
#include"Output.h"
#include"Input.h"
#include"Card.h"
#include"CellPosition.h"

CardCutAction::CardCutAction(ApplicationManager* pApp) : Action(pApp)
{
	myCard = NULL;
}

void CardCutAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Cut Card:Select a Card to Cut ...");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CardCutAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (cardPosition.IsValidCell()) {
		myCard = pGrid->CheckForCards(cardPosition);
		if (myCard == NULL)
		{
			pGrid->PrintErrorMessage("Cell has no card ! Click anywhere to con ......");
		}
		else
		{
			pGrid->SetClipboard(myCard);
			pGrid->SetCutState(true);
			//pGrid->RemoveObjectFromCell(cardPosition);
			pGrid->PrintErrorMessage("Card has been Cut ! Click anywhere to con ......");
		}
	}
	pOut->ClearStatusBar();
}

CardCutAction::~CardCutAction()
{
}
