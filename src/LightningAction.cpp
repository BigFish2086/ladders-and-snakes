#include "LightningAction.h"

#include "Grid.h"
#include"Output.h"
#include"Input.h"
#include "Player.h"

LigthningAction::LigthningAction()
{
}

void LigthningAction::ReadActionParameters(Grid* pGrid)
{
}

bool LigthningAction::Execute(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* Attacker = pGrid->GetCurrentPlayer();
	Player* victim;
	if (Attacker->GetLightningPower()) {
		for (int i = 0; i < MaxPlayerCount - 1; i++) {
			pGrid->AdvanceCurrentPlayer();
			victim = pGrid->GetCurrentPlayer();
			victim->SetWallet(victim->GetWallet() - 20);
		}
		pGrid->PrintErrorMessage("All players expect P" + to_string(Attacker->GetPlayerNumber()) + " has lost 20 coin ! click anywhere to con ...");
		pGrid->AdvanceCurrentPlayer();
		Attacker->SetLightningPower(false);
		Attacker->SetNumberOfAttacks(Attacker->GetNumberOfAttacks() + 1);
		Attacker->setTurnCount(0);
		return true;
	}
	else {
		pGrid->PrintErrorMessage("You cann't use this lightning attack any more ..");
		return false;
	}
	pOut->ClearStatusBar();
}

LigthningAction::~LigthningAction()
{
}
