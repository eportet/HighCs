// Dock.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef DOCK_H
#define DOCK_H

#include "GameObject.h"

class Sailor;
class Model;

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
	
	double get_berths();

	bool update();
	void show_status();

	void save(ofstream&);
	void restore(ifstream&, Model&);

	// From GameObject
	// CartPoint get_location();
	// int get_id();
	// char get_display_code();
	// char get_state();
};

#endif