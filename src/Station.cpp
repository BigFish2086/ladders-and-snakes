#include "Station.h"

Station::Station(const CellPosition& pos) : Card(pos)
{
	/*price = 0;
	fees = 0;*/
}

void Station::ReadCardParameters(Grid* pGrid)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardTen : A station for you to buy ...");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("enter its price : ");
	price = pIn->GetInteger(pOut);
	pOut->PrintMessage("enter the fees to be paid : ");
	fees = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void Station::Apply(Grid* pGrid, Player* pPlayer, Player*& owner,double myPrice,double myFees)
{
	Card::Apply(pGrid, pPlayer);
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);
	if (owner == NULL) {
		pOut->PrintMessage("You have reached an empty station.Do you want to buy? (y/n) :  ");
		string ans = pIn->GetSrting(pOut);
		ans = pIn->Format(ans);
		if (ans == "y" || ans == "yes") {
			owner = pPlayer;
			owner->SetWallet(pPlayer->GetWallet() - myPrice);	
		}
	}
	else {
		if (pPlayer->GetPlayerNumber() == owner->GetPlayerNumber()) {
			pOut->PrintMessage("This is your station");
			pIn->GetPointClicked(x, y);
		}
		else {
			pOut->PrintMessage("This station is owned by P" + to_string(owner->GetPlayerNumber()));
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("you are going to pay him " + to_string(myFees));
			pPlayer->SetWallet(pPlayer->GetWallet() - myFees);
			owner->SetWallet(owner->GetWallet() + myFees);
			pIn->GetPointClicked(x, y);
		}
	}
	pOut->ClearStatusBar();
}

double Station::GetPrice() const
{
	return price;
}

double Station::GetFees() const
{
	return fees;
}

Station::~Station()
{
}
