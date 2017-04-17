// View.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef VIEW_H
#define VIEW_H

#include "CartPoint.h"
#include "GameObject.h"

using namespace std;

// Max size of grid
const int view_maxsize = 20;

class View
{
private:
	// Private member variables
	int size;
	double scale;
	CartPoint origin;
	char grid[view_maxsize][view_maxsize][2]; // 2 char array

	// Private member functions
	bool get_subscripts(int&, int&, CartPoint);
	
public:
	// Constructors
	View();
	~View();

	// Public member functions
	void clear();
	void plot(GameObject*);
	void draw();
};

#endif