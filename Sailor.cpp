// Sailor.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "Dock.h"
#include <iostream>
#include <cmath>

using namespace std;

//				//
// CONSTRUCTORS //
//				//

// Default constructor sets everything to initial values
Sailor::Sailor() : GameObject('S', 0)
{
	state = 'a';
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	destination = CartPoint();
	cout << "Sailor default constructed" << endl;
}

// Set everything to initial values except for ID and hideout
Sailor::Sailor(int in_id, Dock* in_hideout) : GameObject('S', in_id, in_hideout->get_location())
{
	state = 'h';
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	hideout = in_hideout;
	destination = in_hideout->get_location();
	cout << "Sailor constructed" << endl;
}

// Destructor
Sailor::~Sailor()
{
	cout << "Sailor destructed.\n";
}

//					//
// MEMBER FUNCTIONS //
//					//

double Sailor::get_size()
{
	return size;
}

double Sailor::get_cargo()
{
	return cargo;
}

double Sailor::get_speed()
{
	return (size - (cargo*.1));
}

// Updates the objects location
bool Sailor::update_location()
{
	// check whether it is within one step of destination
	if ((fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) || (location.x == destination.x && location.y == destination.y))
	{
		// if it is sets the location to the destination
		// prints arrived message and returns true
		location = destination;
		cout << display_code << get_id() << ": I’m there!\n";
		return true;
	}
	// if it is not within 1 step adds delta to location
	// prints moved message and returns false
	location = location + delta;
	cout << display_code << get_id() << ": Just keep sailing...\n";
	
	return false;
}

// Sets destination and calculates the delta value
void Sailor::setup_destination(CartPoint dest)
{
	destination = dest;
	delta = (destination - location)*(get_speed()/cart_distance(destination, location));
}

// Returns true if the sailor is at the hideout
bool Sailor::is_hidden()
{
	if (location.x == hideout->get_location().x && location.y == hideout->get_location().y)
		return true;
	return false;
}

// Tells the sailor to move to a point
void Sailor::start_sailing(CartPoint dest)
{
	if (state == 'd')
		dock->set_sail(this);
	
	setup_destination(dest);
	state = 's';
	cout << display_code << get_id() << ": On my way\n";
}

// Tells the sailor to start supplying at the given port
void Sailor::start_supplying(Port* destPort)
{
	if (state == 'd')
		dock->set_sail(this);

	port = destPort;
	setup_destination(port->get_location());
	state = 'o';
	cout << display_code << get_id() << ": Supplies here I come!\n";
}

// Tells the sailor to go to hideout
void Sailor::start_hiding()
{
	if (state == 'd')
		dock->set_sail(this);
	
	setup_destination(hideout->get_location());
	state = 'h';
	cout << display_code << get_id() << ": Off to hide\n";
}

// Tells sailor to go to dock given
void Sailor::start_docking(Dock* destDock)
{
	if (this->state == 'd')
		dock->set_sail(this);


	dock = destDock;
	setup_destination(dock->get_location());
	state = 'i';
	cout << display_code << get_id() << ": Off to Dock\n";
}

// Tells the sailor to stop an anchor
void Sailor::anchor()
{
	if (state == 'd')
		dock->set_sail(this);

	state = 'a';
	cout << display_code << get_id() << ": Dropping anchor\n";
}

// returns true if an event happens
bool Sailor::update()
{
	switch (state)
	{
		case 'a':
		case 'd':
		case 't':
			return false;

		case 's':
			if (update_location())
			{
				state = 'a';
				return true;
			}
			return false;
		
		case 'o':
			if (update_location())
			{
				state = 'l';
				cout << display_code << get_id() << ": Starting to supply at a port\n";
				return true;
			}
			return false;
		
		case 'i':
			if (update_location())
			{
				state = 'u';
				cout << display_code << get_id() << ": Starting to unload at a dock\n";
				return true;
			}
			return false;
		
		case 'l':
			if (cargo == hold)
			{
				state = 'a';
				cout << display_code << get_id() << ": My boat is filled up. Send me to a Dock to unload. Dropping anchor\n";
				return true;
			}
			else
			{
				if (port->is_empty())
				{
					state ='a';
					cout << display_code << get_id() << ": This Port has no more supplies for me. Dropping anchor\n";
					return true;
				}
				cargo += port->provide_supplies();
				if (cargo > hold)
					cargo = hold;
				cout << display_code << get_id() << ": My new cargo is " << cargo << endl;
				return false;
			}
		
		case 'u':
			if (dock->dock_boat(this))
			{
				if (cargo > 0)
				{
					hold += 20;
					size += 5;
					cargo = 0;
				}
				state = 'd';
				cout << display_code << get_id() << ": I am unloading at the dock\n";
				return true;
			}
			state = 't';
			cout << display_code << get_id() << ": Help! My home dock is full\n";
			return true;
		
		case 'h':
			if (update_location())
			{
				state = 'a';
				return true;
			}
			return false;
		
		default:
			cout << "Unknown state\n";
			return false;
	}
}

// show the status depending on the status
void Sailor::show_status()
{
	//Sample: Sailor Status: S with ID 1 at location (5, 1) is anchored. Has a size of: 20, cargo of: 120, hold of: 120, and health of: 25
	cout << "Sailor status: "; 
	GameObject::show_status();
	switch (state)
	{
		case 'a':
			if (is_hidden())
			{
				cout << " is anchored (and hiding). Has a size of: " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
				break;
			}
			cout << " is anchored. Has a size of: " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
			break;

		case 'h':
			cout << " is going to hide at Dock " << hideout->get_id() << endl;
			break;

		case 's':
			cout << " Has a speed of: " << get_speed() << " and is heading to: " << destination << endl;
			break;

		case 'o':
			cout << " is outbound to Port: " << port->get_id() << " with a speed of " << get_speed() << endl;
			break;

		case 'i':
			cout << " is inbound to Dock: " << dock->get_id() << " with a speed of " << get_speed() << endl;
			break;

		case 'l':
			cout << " is supplying at Port " << port->get_id() << endl;
			break;

		case 'u':
			cout << " is unloading at Dock " << dock->get_id() << endl;
			break;

		case 'd':
			cout << " is docked at Dock " << dock->get_id() << endl;
			break;

		case 't':
			cout << " is in trouble " << get_id() << endl;
			break;

		default:
			cout << "Unknown state" << endl;
			break;
	}
}

