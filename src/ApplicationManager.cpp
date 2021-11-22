#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "CardCopyAction.h"
#include"CardPasteAction.h"
#include"CardCutAction.h"
#include "CardEditAction.h"
#include "DeleteGameObjectAction.h"
#include "RollDiceAction.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "InputDiceVlaueAction.h"
#include "NewGameAction.h"

#include<iostream>


///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid* ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case OPEN_GRID:
		pAct = new LoadAction(this);
		break;

	case SAVE_GRID:
		pAct = new SaveAction(this);
		break;

	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case DELETE_OBJECT:
		pAct = new DeleteGameObjectAction(this);
		break;

	case COPY_CARD:
		pAct = new CardCopyAction(this);
		break;

	case PASTE_CARD:
		pAct = new CardPasteAction(this);
		break;

	case CUT_CARD:
		pAct = new CardCutAction(this);
		break;

	case EDIT_CARD:
		pAct = new CardEditAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case NEW_GAME:
		pAct = new NewGameAction(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case INPUT_VALUE:
		pAct = new InputDiceVlaueAction(this);
		break;

	case TO_DESIGN_MODE:
		pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();// Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
