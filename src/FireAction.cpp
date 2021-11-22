#include "FireAction.h"

#include "Grid.h"
#include"Output.h"
#include"Input.h"
#include "Player.h"

FireAction::FireAction()
{
}

void FireAction::ReadActionParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Choose a player to be burned for the next turn..");
	victimNum = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

bool FireAction::Execute(Grid* pGrid)
{
	ReadActionParameters(pGrid);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* Attacker = pGrid->GetCurrentPlayer();
	if (!(victimNum >= 0 && victimNum <= 3) || (victimNum == Attacker->GetPlayerNumber())) {
		pGrid->PrintErrorMessage("Invalid Choice.click to con...");
		return false;
	}
	else {
		if (Attacker->GetFirePower()) {
			Player* victim = pGrid->SelectPlayer(victimNum);
			victim->SetBurned(true);
			victim->SetBurningTime(victim->GetBurningTime() + 3);
			Attacker->SetFirePower(false);
			Attacker->SetNumberOfAttacks(Attacker->GetNumberOfAttacks() + 1);
			Attacker->setTurnCount(0);
			return true;
		}
		else {
			pGrid->PrintErrorMessage("You cann't use this fire attack any more ..");
			return false;
		}

	}
	pOut->ClearStatusBar();
}

FireAction::~FireAction()
{
}
