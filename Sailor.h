// Sailor.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef SAILOR_H
#define SAILOR_H
#include <iostream>
#include "Port.h"
using namespace std;

class Dock;

class Sailor: public GameObject
{
private:
	double health;
	double size;
	double hold;
	double cargo;
	CartPoint destination;
	CartVector delta;
	Port *port;
	Dock *dock;
	Dock *hideout;

	// Private member functions
	bool update_location();
	void setup_destination(CartPoint);

public:
	// Constructors
	Sailor();
	Sailor(int, Dock*);
	~Sailor();

	// Public member functions
	double get_size();
	double get_cargo();
	double get_speed();
	bool update();
	bool is_hidden();
	void start_sailing(CartPoint);
	void start_supplying(Port*);
	void start_hiding();
	void start_docking(Dock*);
	void anchor();
	void show_status();
};

#endif