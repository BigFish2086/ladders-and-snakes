#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet

	bool moveAction;

	int numberOfAttacks;
	bool lightningPower;
	bool firePower;
	bool icePower;
	bool poisonPower;

	bool burned;
	int burningTime;
	bool poisoned;
	int poisonTime;
	
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	void setTurnCount(int turnCount);
	int GetTurnCount() const;		// A getter for the turnCount

	int GetPlayerNumber() const;

	void SetJustRolledDiceNum(int dice);
	int GetJustRolledDiceNum() const;

	void SetMoveAction(bool state);
	bool GetMoveAction() const;

	void SetNumberOfAttacks(int num);
	int GetNumberOfAttacks() const;

	void SetLightningPower(bool state);
	bool GetLightningPower() const;

	void SetFirePower(bool state);
	bool GetFirePower() const;

	void SetIcePower(bool state);
	bool GetIcePower() const;

	void SetPoisonPower(bool state);
	bool GetPoisonPower() const;

	void SetBurned(bool state);
	bool GetBurned() const;

	void SetBurningTime(int time);
	int GetBurningTime() const;

	void SetPoisoned(bool state);
	bool GetPoisoned() const;

	void SetPoisonTime(int time);
	int GetPoisonTime() const;

	void IsBurned();
	void IsPoisoned(int& diceNumber);

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

};

