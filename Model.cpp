// Model.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include <fstream>
#include <cstdlib>
#include <iostream>
#include "Model.h"
#include "Dock.h"
#include "Sailor.h"
#include "GameObject.h"
#include "Port.h"
#include "View.h"
#include "Merchant.h"
#include "Pirate.h"

using namespace std;

//				//
// CONSTRUCTORS //
//				//

// Default model constructor
Model::Model()
{
	time = 0;

	// Creating 3 dock objects
	Dock* dockA = new Dock(1, CartPoint(5,1));
	Dock* dockB = new Dock(2, CartPoint(6,2));
	Dock* dockC = new Dock(3, CartPoint(1,8));
	dock_ptrs.push_back(dockA);
	dock_ptrs.push_back(dockB);
	dock_ptrs.push_back(dockC);

	// Creating 4 port objects
	Port* portA = new Port(1, CartPoint(1,20));
	Port* portB = new Port(2, CartPoint(20,1));
	Port* portC = new Port(3, CartPoint(20,20));
	Port* portD = new Port(4, CartPoint(7,2));
	port_ptrs.push_back(portA);
	port_ptrs.push_back(portB);
	port_ptrs.push_back(portC);
	port_ptrs.push_back(portD);

	// Creating 3 merchant objects
	Merchant* merchantA = new Merchant(1, dockA, this);
	Merchant* merchantB = new Merchant(2, dockA, this);
	Merchant* merchantC = new Merchant(3, dockB, this);
	sailor_ptrs.push_back(merchantA);
	sailor_ptrs.push_back(merchantB);
	sailor_ptrs.push_back(merchantC);

	// Creating 2 pirate objects
	Pirate* pirateA = new Pirate(4, this);
	Pirate* pirateB = new Pirate(5, this);
	sailor_ptrs.push_back(pirateA);
	sailor_ptrs.push_back(pirateB);

	// Creating 12 objects
	
	object_ptrs.push_back(dynamic_cast<GameObject*>(dockA));
	object_ptrs.push_back(dynamic_cast<GameObject*>(dockB));
	object_ptrs.push_back(dynamic_cast<GameObject*>(dockC));
	
	object_ptrs.push_back(dynamic_cast<GameObject*>(portA));
	object_ptrs.push_back(dynamic_cast<GameObject*>(portB));
	object_ptrs.push_back(dynamic_cast<GameObject*>(portC));
	object_ptrs.push_back(dynamic_cast<GameObject*>(portD));
	
	object_ptrs.push_back(dynamic_cast<GameObject*>(merchantA));
	object_ptrs.push_back(dynamic_cast<GameObject*>(merchantB));
	object_ptrs.push_back(dynamic_cast<GameObject*>(merchantC));
	
	object_ptrs.push_back(dynamic_cast<GameObject*>(pirateA));
	object_ptrs.push_back(dynamic_cast<GameObject*>(pirateB));
	
	active_ptrs = (object_ptrs);

	cout << "Model default constructed\n";
}

// Destructor
Model::~Model()
{
	// Delete objects
	for (itObject = object_ptrs.begin(); itObject != object_ptrs.end(); itObject++)
	{
		delete *itObject;
	}
	cout << "Model destructed\n";
}

// Copy constructor
Model::Model(Model &model) {}

//					//
// MEMBER FUNCTIONS //
//					//

// Iterates over sailor array and returns correct sailor
Sailor* Model::get_Sailor_ptr(int id_num)
{
	for (itSailor = sailor_ptrs.begin(); itSailor != sailor_ptrs.end(); ++itSailor)
	{
		int in_id = (**itSailor).get_id();
		if (in_id == id_num)
			return *itSailor;
	}
	return NULL;
}

// Iterates over merchant array and returns correct sailor
Merchant* Model::get_Merchant_ptr(int id_num)
{
	for (itSailor = sailor_ptrs.begin(); itSailor != sailor_ptrs.end(); ++itSailor)
	{
		int in_id = (**itSailor).get_id();
		if (in_id == id_num)
			return dynamic_cast<Merchant*>(*itSailor);
	}
	return NULL;
}

// Iterates over port array and returns correct port
Port* Model::get_Port_ptr(int id_num)
{
	for (itPort = port_ptrs.begin(); itPort != port_ptrs.end(); ++itPort)
	{
		int in_id = (**itPort).get_id();
		if (in_id == id_num)
			return *itPort;
	}
	return NULL;
}

// Iterates over port array and returns correct port
Dock* Model::get_Dock_ptr(int id_num)
{
	for (itDock = dock_ptrs.begin(); itDock != dock_ptrs.end(); ++itDock)
	{
		int in_id = (**itDock).get_id();
		if (in_id == id_num)
			return *itDock;
	}
	return NULL;
}

void Model::add_new_object(GameObject* newObject)
{
	char newType;
	newType = newObject->get_display_code();

	if (newType == 'M')
	{
		Merchant* newMerchant = dynamic_cast<Merchant*>(newObject);
		sailor_ptrs.push_back(newMerchant);
		object_ptrs.push_back(newMerchant);
		active_ptrs.push_back(newMerchant);
	}
	else if (newType == 'R')
	{
		Pirate* newPirate = dynamic_cast<Pirate*>(newObject);
		sailor_ptrs.push_back(newPirate);
		object_ptrs.push_back(newPirate);
		active_ptrs.push_back(newPirate);
	}
	else if ((newType == 'P') || (newType == 'p'))
	{
		Port* newPort = dynamic_cast<Port*>(newObject);
		port_ptrs.push_back(newPort);
		object_ptrs.push_back(newPort);
		active_ptrs.push_back(newPort);
	}
	else if ((newType == 'D') || (newType == 'd'))
	{
		Dock* newDock = dynamic_cast<Dock*>(newObject);
		dock_ptrs.push_back(newDock);
		object_ptrs.push_back(newDock);
		active_ptrs.push_back(newDock);
	}
	else
	{
		Sailor* newSailor = dynamic_cast<Sailor*>(newObject);
		sailor_ptrs.push_back(newSailor);
		object_ptrs.push_back(newSailor);
		active_ptrs.push_back(newSailor);
	}
}

CartPoint Model::gen_location()
{
    return CartPoint(rand()%20, rand()%20);
}

Sailor* Model::get_merchants(Merchant* in_merch)
{
	
	for (itSailor = sailor_ptrs.begin(); itSailor != sailor_ptrs.end(); itSailor++) // For all merchants
	{
		Sailor* test_merchant = *itSailor;

		//cout << "CHECKING M" << in_merch->get_id() << in_merch->get_state() << " WITH M" << test_merchant->get_id() << test_merchant->get_state() << endl;
		
		char test_code = test_merchant->get_display_code();
		char test_state = test_merchant->get_state();
		int test_id = test_merchant->get_id();


		if (test_code == 'R' || in_merch->get_id() == test_id || test_state != 'a')
		{
			//cout << "IT WAS R\n";
			continue;
		}
		else
		{
			int test_hideout = test_merchant->hideout->get_id();
			int actual_hideout = in_merch->hideout->get_id();
			if (actual_hideout == test_hideout)
			{
				cout << "YES\n";
				return test_merchant;
			}
		}
	}
	return NULL;
}

int Model::merchants_at(Dock* in_hideout)
{
	int i = 0;
	for (itSailor = sailor_ptrs.begin(); itSailor != sailor_ptrs.end(); itSailor++)
	{
		Merchant* test_merchant = dynamic_cast<Merchant*>(*itSailor);
		if(!test_merchant->is_alive()) //If it's dead don't just don't you necrophiliac
			continue;
		
		CartPoint test_loc = test_merchant->get_location();

		CartPoint original_loc = in_hideout->get_location();
		
		if(test_loc == original_loc)
		{
			i++;
		}
	}
	return i;
}

int Model::get_merch_id()
{
	for (int i = 1; i < 10; i++)
	{
		Sailor* test = get_Sailor_ptr(i);
		if (test == NULL)
			return i;
	}
	return -1;
}

int Model::get_time()
{
	return time;
}

// Updates all objects in model
bool Model::update()
{
	time++;
	srand(time);

	int events = 0;

	for (itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
	{
		bool action; 
		action = (*itActive)->update(); // check for event

		if (action) // at least one event has occured
			events++;
	}

	// delete all "dead" objects
	for (itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
	{
		if (!(*itActive)->is_alive()) // object is dead
		{
			active_ptrs.erase(itActive); // delete object
		}
	}

	// at least one event occured
	if (events > 0)
		return true;
	else
		return false;
}

// Populates view with all objects and prints the grid
void Model::display(View& view)
{
	cout << "Time: " << time << endl;

	view.clear();

	for (itActive = active_ptrs.begin(); itActive != active_ptrs.end(); ++itActive)
	{
		view.plot(*itActive);
	}

	view.draw();
}

void Model::show_status()
{
	for (itObject = object_ptrs.begin(); itObject != object_ptrs.end(); itObject++)
	{
		(*itObject)->show_status();
	}
}

// GameSaves
void Model::save(ofstream& file)
{
    // save current simulation time
	file << time << endl;

	// Save amount of GameObjects
	file << active_ptrs.size() << endl;

	// Save contents of GameObjects
	for (std::list<GameObject*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
		file << (**it).get_display_code() << (**it).get_id() << endl;

	// Save GameObjects
	for (std::list<GameObject*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
		(**it).save(file);
}

void Model::restore(ifstream& file)
{
	// Delete current GameObjects
	cout << "Restoring game..." << endl;
	cout << "Destroying Objects" << endl;
	for (itObject = object_ptrs.begin(); itObject != object_ptrs.end(); itObject++)
	{
		delete *itObject;
	}

	// Clear LLs
	object_ptrs.clear();
	active_ptrs.clear();
	sailor_ptrs.clear();
	sailor_ptrs.clear();
	port_ptrs.clear();
	dock_ptrs.clear();

	// Load time
	file >> time;

	// Load objects size
	int num_objects;
	file >> num_objects;

	cout << "Constructing Objects" << endl;
	// Restore GameObjects:
	for (int i = 0; i < num_objects; i++)
	{
		// Load display_code
		char in_code;
		int in_num_id;

		file >> in_code >> in_num_id;

		// Default construct GameObjects

		if (in_code == 'r' || in_code == 'R') // Pirate
		{
			Pirate* pirate = new Pirate(in_num_id, NULL);
			add_new_object(pirate);
		}        
		else if(in_code == 'm' || in_code == 'M') // Merchant
		{
			Merchant* merchant = new Merchant(in_num_id, NULL, NULL);
			add_new_object(merchant);
		}
		else if(in_code == 'p' || in_code == 'P') // Port
		{
			Port* port = new Port(in_num_id, CartPoint());
			add_new_object(port);
		}
		else if(in_code == 'd' || in_code == 'D') // Dock
		{
			Dock* dock = new Dock(in_num_id, CartPoint());
			add_new_object(dock);
		}
	}

	// All object ptrs are active
	active_ptrs = object_ptrs;

	// Restore each individual object
	for (std::list<GameObject*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
		(**it).restore(file, *this);
	
	cout << "Game restored!" << endl;
}




















