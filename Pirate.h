// Pirate.h
// PA4 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: December 10, 2015

#ifndef PIRATE_H
#define PIRATE_H

#include "Sailor.h"

class Pirate: public Sailor
{
public:
	// Constructors
	Pirate(Model*);
	Pirate(int, Model*);

	// Public member functions
	double get_speed();
	void start_plunder(Sailor*);
	void start_recruiting(Sailor*);

	bool update();
	void show_status();

	void save(ofstream&);
	void restore(ifstream&, Model&);

	// From Sailor
	// double get_size();
	// double get_presize();
	// double get_cargo();
	// double get_health();
	// bool is_hidden();
	// void start_sailing(CartPoint);
	// void start_supplying(Port*);
	// void start_hiding();
	// void start_docking(Dock*);
	// void anchor();
	// void set_location(double, double);
	// void get_plundered(int);

	// From GameObject
	// CartPoint get_location();
	// int get_id();
	// char get_display_code();
	// char get_state();

private:
	int attack_strength;
	double range;
	Sailor* target;

	// From Sailor
	// double health;
	// double size;
	// double presize;
	// double hold;
	// double cargo;
	// CartPoint destination;
	// CartVector delta;
	// Port* port;
	// Dock* dock;
	// Dock* hideout;
	// Model* world;
	// bool update_location();
	// void setup_destination(CartPoint);

	// From GameObject
	// CartPoint location;
	// char display_code;
	// char state;
};

double gen_loc(int);

#endif