#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include "CardEleven.h"
#include "CellPosition.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* currentPlayer;
	pGrid->PrintErrorMessage("New Game Click to con ....");

	//for loop to return all player to first cell and set their wallet to 100  and return count to zero and set curr player to zero
	//return the game to its intial state
	for (int i = 0; i < MaxPlayerCount; i++)        
	{
		currentPlayer = pGrid->GetCurrentPlayer();
		currentPlayer->SetWallet(100);
		currentPlayer->setTurnCount(0);                  
		pGrid->UpdatePlayerCell(currentPlayer, CellPosition::GetCellPositionFromNum(1));  //return player to 
		pGrid->AdvanceCurrentPlayer();              
	}
	CardTen::setOwner(NULL);                         //set the owners of cards 10 -> 14 (stations) to null as I started a new game  
	CardEleven::setOwner(NULL);
	CardTwelve::setOwner(NULL);
	CardThirteen::setOwner(NULL);
	CardFourteen::setOwner(NULL);
	pGrid->setCurrentPlayer(0);          
}

NewGameAction::~NewGameAction()
{
}
