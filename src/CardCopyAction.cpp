#include "CardCopyAction.h"

#include"Grid.h"
#include"Output.h"
#include"Input.h"
#include"Card.h"
#include"CellPosition.h"

#include<iostream>

CardCopyAction::CardCopyAction(ApplicationManager* pApp) : Action(pApp)
{
	myCard = NULL;
}

void CardCopyAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Copy Card. Select a Card to copy ...");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CardCopyAction::Execute()
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
			pGrid->SetCutState(false);
			pGrid->PrintErrorMessage("Card has been copied ! Click anywhere to con ......");
		}
	}
	
	pOut->ClearStatusBar();
}

CardCopyAction::~CardCopyAction()
{
}
