// GameObject.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "CartPoint.h"
#include <iostream>

class Model;

class GameObject
{
public:
	// Constructors
	GameObject(char, int);
	GameObject(char, int, CartPoint);
	virtual ~GameObject();

	// Public member funtions
	// Getter Functions
	CartPoint get_location();
	int get_id();
	char get_display_code();
	char get_state();
	virtual bool is_alive();

	void set_location(double, double);
	void set_id(int);

	// View Functions
	void drawself(char *);

	// Status Functions
	virtual void show_status();
	virtual bool update() = 0; // Pure virtual function

	// GameSaves
	void save(ofstream&);
	void restore(ifstream&, Model&);

protected:
	CartPoint location;
	char display_code;
	char state;

private:
	int id_num;
};

#endif