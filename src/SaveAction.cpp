#include "SaveAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "CellPosition.h"

#include<iomanip>
#include<iostream>
#include<fstream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
	fileName = "";
}

void SaveAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the saved file name (it's \"test.txt\" by default) : ");
	fileName = pIn->GetSrting(pOut);
	bool filled = false;
	for (auto c : fileName) {
		if (c != ' ') {
			filled = true;
			break;
		}
	}
	if (!filled) {
		fileName = "test";
	}
	fileName += ".txt";
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	string ans;
	ifstream inFile{ fileName };
	ofstream outFile;
	if (inFile) {
		pOut->PrintMessage("The file already exists.Do you want to overwrite it? (y/n) : ");
		ans = pIn->GetSrting(pOut);
		ans = pIn->Format(ans);
		if (ans == "y" || ans == "yes") {
			outFile.open(fileName);
			this->Save(outFile, pGrid);
		}
		else {
			pGrid->PrintErrorMessage("The file hasn't been saved...");
		}
	}
	else if (!inFile) {
		outFile.open(fileName);
		this->Save(outFile, pGrid);
	}
	inFile.close();
	outFile.close();
}

void SaveAction::Save(ofstream& outFile, Grid* pGrid)
{
	int ladderType = 0;
	int snakeType = 1;
	int cardType = 2;
	if (outFile) {
		pGrid->SaveAll(outFile, ladderType);
		pGrid->SaveAll(outFile, snakeType);
		pGrid->SaveAll(outFile, cardType);
		pGrid->PrintErrorMessage("The file has been saved correctly...");
	}
	else {
		pGrid->PrintErrorMessage("Something went wrong while saving..");
	}
}

SaveAction::~SaveAction()
{
}
