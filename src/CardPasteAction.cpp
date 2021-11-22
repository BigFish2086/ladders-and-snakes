#include "CardPasteAction.h"

#include"Grid.h"
#include"Output.h"
#include"Input.h"
#include"Card.h"
#include"CellPosition.h"

CardPasteAction::CardPasteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CardPasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->GetClipboard() == NULL) {
		pGrid->PrintErrorMessage("NO Card Was Copied ! Click Anywhere to con .....");
	}
	else {
		pOut->PrintMessage("Paste Card:Select a cell to paste the copied card ...");
		pastePosition = pIn->GetCellClicked();
	}
	pOut->ClearStatusBar();
}

void CardPasteAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pastePosition.IsValidCell()) {
		oldCopy = pGrid->GetClipboard();
		newCopy = oldCopy->Clone();
		if (!pGrid->CheckForCards(pastePosition)) {
			newCopy->SetPosition(pastePosition);
			pGrid->AddObjectToCell(newCopy);
			if (pGrid->getCutState()) {
				pGrid->RemoveObjectFromCell(oldCopy->GetPosition());
				pGrid->SetCutState(false);
				pGrid->SetClipboard(newCopy);
			}
		}
	}
	
	pOut->ClearStatusBar();
}

CardPasteAction::~CardPasteAction()
{
}
