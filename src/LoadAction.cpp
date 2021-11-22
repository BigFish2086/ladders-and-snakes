#include "LoadAction.h"

#include "CellPosition.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"

#include<regex>
#include<iomanip>
#include<iostream>
#include<fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
	fileName = "";
}

void LoadAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter a saved file name : ");
	fileName = pIn->GetSrting(pOut);
	regex reg("([\w.-]*)(.txt)");
	if (!(std::regex_match(fileName, reg))) fileName += ".txt";
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ifstream Infile{ fileName };
	if (Infile) {
		pGrid->RemoveAllObjects();
		CellPosition invalidStart(-1);
		CellPosition invalidEnd(-1);
		Ladder* pLadder = new Ladder(invalidStart,invalidEnd);
		pLadder->Load(Infile,pGrid);
		Snake* pSnake = new Snake(invalidStart, invalidEnd);
		pSnake->Load(Infile, pGrid);
		Card* pCard = new Card(invalidStart);
		pCard->Load(Infile,pGrid);

		delete pLadder;
		delete pSnake;
		delete pCard;
	}
	else {
		pGrid->PrintErrorMessage("This file doesn't exist");
	}
	Infile.close();
}

LoadAction::~LoadAction()
{
}
