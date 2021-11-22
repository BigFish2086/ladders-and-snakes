#include "Card.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

#include <iostream>
#include <fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	editAction = false;
}

void Card::SetCardNumber(int cnum)
{
	if (cnum >= 1 && cnum <= 14) {
		cardNumber = cnum; // needs validation
	}
}

int Card::GetCardNumber() const
{
	return cardNumber;
}

void Card::setEditAction(bool state)
{
	editAction = state;
}

bool Card::getEditAction() const
{
	return editAction;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(GetPosition(), GetCardNumber());

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, int type)
{
	if (type == 2) {
		string number = to_string(cardNumber);
		string pos = to_string(GetPosition().GetCellNum());
		OutFile << number + " " + pos + " ";
	}
}

void Card::Load(ifstream& Infile, Grid* pGrid)
{
	int numberOfCards;
	int currCardNumber;
	int currCardPos;
	Infile >> numberOfCards;
	for (int i = 0; i < numberOfCards; i++) {
		Infile >> currCardNumber >> currCardPos;
		CellPosition cardPosition(currCardPos);
		Card* pCard = NULL; 
		switch (currCardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTen(cardPosition);
			break;
		case 11:
			pCard = new CardEleven(cardPosition);
			break;
		case 12:
			pCard = new CardTwelve(cardPosition);
			break;
		case 13:
			pCard = new CardThirteen(cardPosition);
			break;
		case 14:
			pCard = new CardFourteen(cardPosition);
			break;
		}
		if (pCard)
		{
			pCard->Read(Infile);
			bool added = pGrid->AddObjectToCell(pCard);
			/*if (!added) {
				pGrid->PrintErrorMessage("the card can not be added to this postion ...");
			}*/
		}
	}
}

void Card::Read(ifstream& Infile)
{
}

Card* Card::Clone() const
{
	return nullptr;
}

Card::~Card()
{
}
