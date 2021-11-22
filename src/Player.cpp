#include "Player.h"

#include "GameObject.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "LightningAction.h"
#include "IceAction.h"
#include "FireAction.h"
#include "PoisonAction.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	this->numberOfAttacks = 0;
	this->lightningPower = true;
	this->firePower = true;
	this->icePower = true;
	this->poisonPower = true;

	this->burned = false;
	this->burningTime = 0;
	this->poisoned = false;
	this->poisonTime = 0;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::setTurnCount(int turnCount)
{
	this->turnCount = turnCount;
}

int Player::GetPlayerNumber() const
{
	return playerNum;
}

void Player::SetJustRolledDiceNum(int dice)
{
	this->justRolledDiceNum = dice;
}

int Player::GetJustRolledDiceNum() const
{
	return justRolledDiceNum;
}

void Player::SetMoveAction(bool state)
{
	moveAction = state;
}

bool Player::GetMoveAction() const
{
	return moveAction;
}

void Player::SetNumberOfAttacks(int num)
{
	this->numberOfAttacks = num;
}

int Player::GetNumberOfAttacks() const
{
	return this->numberOfAttacks;
}

void Player::SetLightningPower(bool state)
{
	this->lightningPower = state;
}

bool Player::GetLightningPower() const
{
	return this->lightningPower;
}

void Player::SetFirePower(bool state)
{
	this->firePower = state;
}

bool Player::GetFirePower() const
{
	return this->firePower;
}

void Player::SetIcePower(bool state)
{
	this->icePower = state;
}

bool Player::GetIcePower() const
{
	return this->icePower;
}

void Player::SetPoisonPower(bool state)
{
	this->poisonPower = state;
}

bool Player::GetPoisonPower() const
{
	return this->poisonPower;
}

void Player::SetBurned(bool state)
{
	this->burned = state;
}

bool Player::GetBurned() const
{
	return this->burned;
}

void Player::SetBurningTime(int time)
{
	this->burningTime = time;
}

int Player::GetBurningTime() const
{
	return this->burningTime;
}

void Player::SetPoisoned(bool state)
{
	this->poisoned = state;
}

bool Player::GetPoisoned() const
{
	return this->poisoned;
}

void Player::SetPoisonTime(int time)
{
	this->poisonTime = time;
}

int Player::GetPoisonTime() const
{
	return this->poisonTime;
}

void Player::IsBurned()
{
	if (this->GetBurned()) {
		if (this->GetBurningTime() > 0) {
			this->SetWallet(this->GetWallet() - 20);
			this->SetBurningTime(this->GetBurningTime() - 1);
		}
		else {
			this->SetBurned(false);
		}
	}
}

void Player::IsPoisoned(int& diceNumber)
{
	if (this->GetPoisoned()) {
		if (this->GetPoisonTime() > 0) {
			diceNumber--;
			this->SetPoisonTime(this->GetPoisonTime() - 1);
		}
		else {
			this->SetPoisoned(false);
		}
	}
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(GetCell()->GetCellPosition(), GetPlayerNumber(), playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(GetCell()->GetCellPosition(), GetPlayerNumber(), cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	IsBurned();
	IsPoisoned(diceNumber);

	if (!GetMoveAction()) {
		pGrid->PrintErrorMessage("This player isn't moving this turn ..");
		SetMoveAction(true);
		return;
	}
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	this->turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (GetTurnCount() == 3) {
		bool attackCompelete = false;
		if (this->GetNumberOfAttacks() < 2) {
			pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? (y/n) ");
			string ans = pIn->GetSrting(pOut);
			ans = pIn->Format(ans);
			if (ans == "y" || ans == "yes") {
				pOut->PrintMessage("choose     1-ice     2-fire     3-posion     4-lightning");
				int num = pIn->GetInteger(pOut);
				switch (num) {
				case 1:
				{
					IceAction ice;
					attackCompelete = ice.Execute(pGrid);
					break;
				}
				case 2:
				{
					FireAction fire;
					attackCompelete = fire.Execute(pGrid);
					break;
				}
				case 3:
				{
					PoisonAction poison;
					attackCompelete = poison.Execute(pGrid);
					break;
				}
				case 4:
				{
					LigthningAction ligthning;
					attackCompelete = ligthning.Execute(pGrid);
					break;
				}

				}
			}
			else {
				attackCompelete = false;
			}
		}
		else {
			pGrid->PrintErrorMessage("You ran out of special attacks..");
			pOut->ClearStatusBar();
		}
		if (attackCompelete) return;
		else {
			SetWallet(GetWallet() + diceNumber * 10);
			this->turnCount = 0;
			return;
		}
	}
	if (this->GetWallet() < 0) {
		pGrid->PrintErrorMessage("This player isn't moving this turn.He hasn't enough money..");
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = GetCell()->GetCellPosition();
	pos.AddCellNum(justRolledDiceNum);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	GameObject* pGObj = this->GetCell()->GetGameObject();
	GameObject* pGObj_2 = NULL;
	while (pGObj) {
		pGObj->Apply(pGrid, this);
		pGObj_2 = this->GetCell()->GetGameObject();
		if (pGObj_2 != pGObj) {
			pGObj = pGObj_2;
		}
		else {
			pGObj = NULL;
			pGObj_2 = NULL;
			break;
		}

	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pos.GetCellNum() == 99) {
		pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}