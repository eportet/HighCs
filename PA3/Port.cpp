// Port.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include <iostream>
#include "Port.h"
using namespace std;

//				//
// CONSTRUCTORS //
//				//

// Default constructor sets inventory to 500 state to f and code to P
Port::Port() : GameObject('P', 0)
{
	state = 'f';
	inventory = 500;
	cout << "Port default constructed\n";
}

// Constructor sets inventory to 500 state to f and code to P and location to in_loc
Port::Port(int in_id, CartPoint in_loc): GameObject ('P', in_id, in_loc)
{
	state = 'f';
	inventory = 500;
	cout << "Port constructed\n";
}

// Destructor
Port::~Port()
{
	cout << "Port destructed.\n";
}

//					//
// MEMBER FUNCTIONS //
//					//

// returns true if the port is empty and false otherwise
bool Port::is_empty()
{
	if (inventory == 0)
		return true;
	return false;
}

// removes set amount of supplies or as much as it can give
double Port::provide_supplies(double amount_to_provide)
{
	if (inventory > amount_to_provide)
	{
		inventory -= amount_to_provide;
		return amount_to_provide;
	}
	else if (inventory == amount_to_provide)
	{
		inventory = 0;
		return amount_to_provide;
	}
	double temp = inventory;
	inventory = 0;
	return temp;
}

// retruns true if the state and display code were updated else returns false
bool Port::update()
{
	if (state != 'e' && inventory == 0)
	{
		state = 'e';
		display_code = 'p';
		cout << "Port " << get_id() << " has been depleted of supplies" << endl;
		return true; 
	}
	return false;
}

// Overloads function from GameObject to show state and inventory
void Port::show_status()
{
	// Port Status: P with ID 4 at location (7, 2) containing supplies 500
	cout << "Port Status: ";
	GameObject::show_status();
	cout << " containing supplies " << inventory << endl;
}

