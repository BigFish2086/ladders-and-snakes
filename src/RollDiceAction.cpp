#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include <time.h> // used to in srand to generate random numbers with different seed
#include "CardSeven.h"
#include "CardEight.h"

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	if (pGrid->GetEndGame()) {
		int playerNumber = currentPlayer->GetPlayerNumber();
		pOut->PrintMessage("The game has ended.Player p" + to_string(playerNumber) + " has won ^_^");
		pIn->GetPointClicked(x, y);
		pManager->ExecuteAction(EXIT);
	}
	else {
		// -- If not ended, do the following --:
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		// 3- Get the "current" player from pGrid
		// 4- Move the currentPlayer using function Move of class player
		currentPlayer->Move(pGrid,diceNumber);
		// 5- Advance the current player number of pGrid
		GameObject* currentGamobject = currentPlayer->GetCell()->GetGameObject();
		if (dynamic_cast<CardSeven*>(currentGamobject)) {
			this->Execute();
		}
		/*else if (dynamic_cast<CardEight*>(currentGamobject)) {
			currentPlayer->setTurnCount(currentPlayer->GetTurnCount()-1);
			currentPlayer->Move(pGrid, -diceNumber);
		}*/
		else {
			pGrid->AdvanceCurrentPlayer();
		}
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

RollDiceAction::~RollDiceAction()
{
}
