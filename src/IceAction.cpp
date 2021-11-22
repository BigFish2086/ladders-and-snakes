#include "IceAction.h"

#include "Grid.h"
#include"Output.h"
#include"Input.h"
#include "Player.h"

IceAction::IceAction()
{
}

void IceAction::ReadActionParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Choose a player to be frozen for the next turn..");
	victimNum = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

bool IceAction::Execute(Grid* pGrid)
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
		if (Attacker->GetIcePower()) {
			Player* victim = pGrid->SelectPlayer(victimNum);
			victim->SetMoveAction(false);
			Attacker->SetIcePower(false);
			Attacker->SetNumberOfAttacks(Attacker->GetNumberOfAttacks() + 1);
			Attacker->setTurnCount(0);
			return true;
		}
		else {
			pGrid->PrintErrorMessage("You cann't use this ice attack any more ..");
			return false;
		}
		
	}
	pOut->ClearStatusBar();
}

IceAction::~IceAction()
{
}
