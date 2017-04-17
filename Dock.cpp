// Dock.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "Dock.h"
#include <iostream>

using namespace std;

double original;

//				//
// CONSTRUCTORS //
//				//

// Default constructor sets inventory to 500 state to f and code to P
Dock::Dock() : GameObject('d', 0)
{
	state = 'u';
	berths = 30;
	cout << "Dock default constructed\n";
}

// Constructor sets inventory to 500 state to f and code to P and location to in_loc
Dock::Dock(int in_id, CartPoint in_loc) : GameObject ('d', in_id, in_loc)
{
	state = 'u';
	berths = 30;
	cout << "Dock constructed\n";
}

// Destructor
Dock::~Dock()
{
	cout << "Dock destructed.\n";
}

//					//
// MEMBER FUNCTIONS //
//					//

// returns true if the sailor can dock and false otherwise
bool Dock::dock_boat(Sailor* sailor_to_dock)
{
	if (berths >= sailor_to_dock->get_size())
	{
		original = sailor_to_dock->get_size();
		berths -= original;
		return true;
	}
	return false;
}

// returns true if the port is empty and false otherwise
bool Dock::set_sail(Sailor* sailor_to_sail)
{
	if (sailor_to_sail->get_cargo() == 0)
	{
		berths += original;
		return true;
	}
	return false;
}

// retruns true if the state and display code were updated else returns false
bool Dock::update()
{
	if (state != 'p' && berths == 0)
	{
		state = 'p';
		display_code = 'D';
		cout << "Dock " << get_id() << " is packed\n";
		return true; 
	}
	else if (state == 'p' && berths > 0)
	{
		state = 'u';
		display_code = 'd';
		//cout << "Dock " << get_id() << " is unpacked\n";
		return true;
	}
	return false;
}

// Overloads function from GameObject to show state and inventory
void Dock::show_status()
{
	// Dock Status: d with ID 1 at location (5, 1) has 30 berths
	cout << "Dock Status: ";
	GameObject::show_status();
	cout << " has " << berths << " berths\n";
}

