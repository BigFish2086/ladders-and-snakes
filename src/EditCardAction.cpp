#include "EditCardAction.h"

#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include"CardTen.h"

EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
}

void EditCardAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the cell ...");
	cardPosition = &pIn->GetCellClicked();
	int h,v;
	h=cardPosition->HCell();
	v=cardPosition->VCell();
	cell = pGrid->GetCellPosition(v,h);
	card=cell->HasCard();
	if(card !=NULL)
	{ 
		card->ReadCardParameters(pGrid);
	}
	else
	{
		pOut->PrintMessage("This Cell has not cards");

	}
	/*pOut->PrintMessage("New Card: Enter its number : ");
	pOut->PrintMessage("New Card: Enter its number : ");
	cardNumber = pIn->GetInteger(pOut);*/

	/*if (!(cardNumber >= 1 && cardNumber <= 14)) {
	pGrid->PrintErrorMessage("Invalid card_Number ...");
	}
	if (!cardPosition.IsValidCell()) {
	pGrid->PrintErrorMessage("Invalid cell_position...");
	}*/

}
void EditCardAction::Execute()
{
	ReadActionParameters();
}

EditCardAction::~EditCardAction()
{
}
