// Model.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef MODEL_H
#define MODEL_H

#include <list>
#include "GameObject.h"
#include "Sailor.h"
#include "Merchant.h"
#include "Pirate.h"
#include "View.h"

using namespace std;

class Model
{
public:
	// Constructors
	Model();
	~Model();
	
	// Pointer functions
	Sailor* get_Sailor_ptr(int);
	Merchant* get_Merchant_ptr(int);
	Port* get_Port_ptr(int);
	Dock* get_Dock_ptr(int);

	// Public member functions
	CartPoint gen_location();
	Sailor* get_merchants(Merchant*);
	int merchants_at(Dock*);
	int get_merch_id();
	int get_time();

	bool update();
	void display(View &);
	void show_status();

	// List Iterators
	std::list<GameObject*>::iterator itObject;
	std::list<GameObject*>::iterator itActive;
	std::list<Sailor*>::iterator itSailor;
	std::list<Pirate*>::iterator itPirate;
	std::list<Dock*>::iterator itDock;
	std::list<Port*>::iterator itPort;	

	// LLs
	std::list<Dock*> dock_ptrs;
	std::list<Port*> port_ptrs;
	std::list<Sailor*> sailor_ptrs;
	std::list<GameObject*> object_ptrs;
	std::list<GameObject*> active_ptrs;

    // Adder
	void add_new_object(GameObject*);

    //GameSaves
    void save(ofstream&);
    void restore(ifstream&);

private:
	// Copy constructor
	Model(Model&);

	int time;
};

#endif