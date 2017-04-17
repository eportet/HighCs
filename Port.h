// Port.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef PORT_H
#define PORT_H

#include "GameObject.h"

class Model;

class Port: public GameObject
{
private:
	double inventory;

public:
	// Constructors
	Port();
	Port(int, CartPoint);
	~Port();

	// Public member functions
	bool is_empty();
	double provide_supplies(double amount_to_provide = 50);

	bool update();
	void show_status();

	void save(ofstream&);
	void restore(ifstream&, Model&);
	
};

#endif