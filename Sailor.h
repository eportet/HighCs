// Sailor.h
// PA4 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: December 10, 2015

#ifndef SAILOR_H
#define SAILOR_H

#include "GameObject.h"
#include "Port.h"

class Model;
class Dock;

class Sailor: public GameObject
{
public:
	// Constructors
	Sailor(char, Model*);
	Sailor(char, int, Dock*, Model*);
	Sailor(char, int, CartPoint, Model*);
	~Sailor();

	// Public member functions
	// Getter Functions
	virtual double get_speed() = 0;
	double get_size();
	double get_presize();
	double get_cargo();
	double get_health();
	int get_h_id();
	bool is_hidden();
	bool is_alive();

	// Command Functions
	void start_sailing(CartPoint);
	void start_supplying(Port*);
	void start_hiding();
	void start_docking(Dock*);
	virtual void start_plunder(Sailor*);
	virtual void start_recruiting(Sailor*);

	// Called Functions
	void anchor();
	void get_plundered(int);

	// Status Functions
	virtual bool update();
	void show_status();

	// GameSaves
	void save(ofstream&);
	void restore(ifstream&, Model&);

	// From GameObject
	// CartPoint get_location();
	// int get_id();
	// char get_display_code();
	// char get_state();

	Dock* hideout;

protected:
	// Accessible to Merchant and Pirate
	double health;
	double size;
	double presize;
	double hold;
	double cargo;
	CartPoint destination;
	CartVector delta;
	Port* port;
	Dock* dock;
	Model* world;
	
	// Protected member functions
	bool update_location();
	void setup_destination(CartPoint);

	// From GameObject
	// CartPoint location;
	// char display_code;
	// char state;
	
};

#endif