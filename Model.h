// Model.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef MODEL_H
#define MODEL_H

#include "CartPoint.h"
#include "GameObject.h"
#include "Sailor.h"
#include "Port.h"
#include "Dock.h"
#include "View.h"
#include <iostream>

using namespace std;

class Model
{
private:
	// Copy constructor
	Model(Model&);

	int time;
	
	// Object pointers and number variables
	GameObject** object_ptrs;
	int num_objects;
	Sailor** sailor_ptrs;
	int num_sailors;
	Dock** dock_ptrs;
	int num_docks;
	Port** port_ptrs;
	int num_ports;

public:
	// Constructors
	Model();
	~Model();
	
	// Pointer functions
	Sailor* get_Sailor_ptr(int);
	Port* get_Port_ptr(int);
	Dock* get_Dock_ptr(int);

	// Public member functions
	bool update();
	void display(View &);
	void show_status();	
};

#endif