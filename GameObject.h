// GameObject.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "CartPoint.h"
#include <iostream>

class Model; // Forward declaration of model

using namespace std;

class GameObject
{
private:
	int id_num;

protected:
	CartPoint location;
	char display_code;
	char state;

public:
	// Constructors
	GameObject();
	GameObject(char, int);
	GameObject(char, int, CartPoint);
	virtual ~GameObject();

	// Public member funtions
	CartPoint get_location();
	int get_id();
	virtual void show_status();
	virtual bool update() = 0; // Pure virtual function
	void drawself(char *);
};

#endif