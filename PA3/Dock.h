// Dock.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef DOCK_H
#define DOCK_H
#include <iostream>
#include "GameObject.h"
#include "Sailor.h"
using namespace std;

class Dock: public GameObject
{
private:
	double berths;

public:
	// Constructors
	Dock();
	Dock(int, CartPoint);
	~Dock();

	// Public member functions
	bool dock_boat(Sailor*);
	bool set_sail(Sailor*);
	bool update();
	void show_status();
};

#endif