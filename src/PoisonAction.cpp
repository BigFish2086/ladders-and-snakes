#include "PoisonAction.h"

#include "Grid.h"
#include"Output.h"
#include"Input.h"
#include "Player.h"

PoisonAction::PoisonAction()
{
}

void PoisonAction::ReadActionParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Choose a player to be poisoned for the next turn..");
	victimNum = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

bool PoisonAction::Execute(Grid* pGrid)
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
			victim->SetPoisoned(true);
			victim->SetPoisonTime(victim->GetPoisonTime() + 5);
			Attacker->SetPoisonPower(false);
			Attacker->SetNumberOfAttacks(Attacker->GetNumberOfAttacks() + 1);
			Attacker->setTurnCount(0);
			return true;
		}
		else {
			pGrid->PrintErrorMessage("You cann't use this poison attack any more ..");
			return false;
		}

	}
	pOut->ClearStatusBar();
}

PoisonAction::~PoisonAction()
{
}
