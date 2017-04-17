// Model.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "Model.h"
#include <iostream>

using namespace std;

//				//
// CONSTRUCTORS //
//				//

// Default model constructor
Model::Model()
{
	time = 0;

	// Initializing number variables
	num_objects = 10;
	num_docks = 3;
	num_sailors = 3;
	num_ports = 4;

	// Creating 3 dock objects	
	dock_ptrs = new Dock*[num_docks];
	dock_ptrs[0] = new Dock(1, CartPoint(5, 1));
	dock_ptrs[1] = new Dock(2, CartPoint(6, 2));
	dock_ptrs[2] = new Dock(3, CartPoint(1, 8));
	
	// Creating 4 port objects
	port_ptrs = new Port*[num_ports];
	port_ptrs[0] = new Port(1, CartPoint(1, 20));
	port_ptrs[1] = new Port(2, CartPoint(20, 1));
	port_ptrs[2] = new Port(3, CartPoint(20, 20));
	port_ptrs[3] = new Port(4, CartPoint(7, 2));

	// Creating 3 sailor objects
	sailor_ptrs = new Sailor*[num_sailors];
	sailor_ptrs[0] = new Sailor(1, dock_ptrs[0]);
	sailor_ptrs[1] = new Sailor(2, dock_ptrs[1]);
	sailor_ptrs[2] = new Sailor(3, dock_ptrs[2]);
		
	// Creating 10 objects
	object_ptrs = new GameObject*[num_objects];
	object_ptrs[0] = dock_ptrs[0];
	object_ptrs[1] = dock_ptrs[1];
	object_ptrs[2] = dock_ptrs[2];
	object_ptrs[3] = sailor_ptrs[0];
	object_ptrs[4] = sailor_ptrs[1];
	object_ptrs[5] = sailor_ptrs[2];
	object_ptrs[6] = port_ptrs[0];
	object_ptrs[7] = port_ptrs[1];
	object_ptrs[8] = port_ptrs[2];
	object_ptrs[9] = port_ptrs[3];

	cout << "Model default constructed\n";
}

// Destructor
Model::~Model()
{
	// Delete objects
	for (int i = 0; i < 10; ++i)
	{
		delete object_ptrs[i];
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
	for (int i = 0; i < num_sailors; ++i)
	{
		if (id_num == sailor_ptrs[i]->get_id())
			return sailor_ptrs[i];
	}
	return 0;
}

// Iterates over port array and returns correct port
Port* Model::get_Port_ptr(int id_num)
{
	for (int i = 0; i < num_ports; ++i)
	{
		if (id_num == port_ptrs[i]->get_id())
			return port_ptrs[i];
	}
	return 0;
}

// Iterates over port array and returns correct port
Dock* Model::get_Dock_ptr(int id_num)
{
	for (int i = 0; i < num_docks; ++i)
	{
		if (id_num == dock_ptrs[i]->get_id())
			return dock_ptrs[i];
	}
	return 0;
}

// Updates all objects in model
bool Model::update()
{
	time++;

	int events = 0;
	for (int i = 0; i < num_objects; ++i)
	{
		if (object_ptrs[i]->update())
			events++;
	}

	if (events > 0)
		return true;

	return false;
}

// Populates view with all objects and prints the grid
void Model::display(View& view)
{
	cout << "Time: " << time << endl;

	view.clear();

	for (int i = 0; i < num_objects; ++i)
	{
		view.plot(object_ptrs[i]);
	}

	view.draw();
}

void Model::show_status()
{
	for (int i = 0; i < num_objects; ++i)
	{
		object_ptrs[i]->show_status();
	}
}






















