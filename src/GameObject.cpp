#include "GameObject.h"

#include"Ladder.h"
#include"Snake.h"
#include"Card.h"

GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
	overLapped = false;
}

void GameObject::SetPosition(CellPosition pos)
{
	position = pos;
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject::IsOverlapping()
{
	overLapped = false;
	int start = 0, end = 0;
	Ladder* ladderObj = dynamic_cast<Ladder*>(this);
	Snake* snakeObj = dynamic_cast<Snake*>(this);
	Card* cardObj = dynamic_cast<Card*>(this);
	if (ladderObj) {
		 start = ladderObj->GetPosition().GetCellNum();
		 end = ladderObj->GetEndPosition().GetCellNum();
	}
	else if(snakeObj){
		start = snakeObj->GetEndPosition().GetCellNum();
		end = snakeObj->GetPosition().GetCellNum();
	}
	else if (cardObj) {
		return overLapped;
	}
	for (int i = start; i <= end; i += 11)
	{
		if (i == UI.UsedCells[i]) {
			overLapped = true;
			break;
		}
	}
	if (!overLapped) {
		for (int i = start; i <= end; i += 11)
		{
			UI.UsedCells[i] = i;
		}
	}
	return overLapped;
}

GameObject::~GameObject()
{
}