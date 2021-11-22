#pragma once

#include "Grid.h"

// Base Class for All Game Objects ( ladders, snakes and cards )
class GameObject
{

protected:

	CellPosition position;
	bool overLapped;
	
public:

	GameObject(const CellPosition & pos); // Constructor for initializing data members
	
	void SetPosition(CellPosition pos);
	CellPosition GetPosition() const;     // A Getter for position

	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	 // Draws the game object in the window in his position cell 
											     // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  // Applys the effect of the GameObject on the passed Player
	                                                       // (The effect depends on the GameObject type, so virtual)
	                                                       // For example, applying a ladder is by moving player up, and so on

	// The following functions are examples of what should be supported by the GameObject class
	// They should be overridden by each inherited class

	//[TODO] Decide the parameters that you should pass to each function	
	 bool IsOverlapping();

	
	virtual void Save(ofstream &OutFile,int type) = 0;	// Saves the GameObject parameters to the file
	//type 0->ladder, type 1->snake, type 2->card
	virtual void Load(ifstream &Infile,Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file
	virtual void Read(ifstream &Infile) = 0;

	virtual ~GameObject(); // Virtual destructor
};

