#include "InputDiceVlaueAction.h"

#include"Grid.h"
#include"Player.h"

InputDiceVlaueAction::InputDiceVlaueAction(ApplicationManager* pApp) : Action(pApp)
{
	diceValue = 0;
}

void InputDiceVlaueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter a Dice value : ");
	diceValue = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void InputDiceVlaueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* currentPlayer = pGrid->GetCurrentPlayer();

	if (diceValue > 0 && diceValue <= 6)
	{
		currentPlayer->Move(pGrid, diceValue);
		pGrid->AdvanceCurrentPlayer();
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid dice value ! CLick anywhere to con .....");
	}
}

InputDiceVlaueAction::~InputDiceVlaueAction()
{
}
