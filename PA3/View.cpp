// View.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "View.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//				//
// CONSTRUCTORS //
//				//

// Default constructor
View::View()
{
	size = 11;
	scale = 2;
	origin = CartPoint(0,0);
}

View::~View()
{
	cout << "View destructed.\n";
}

//					//
// MEMBER FUNCTIONS //
//					//


void View::clear()
{
	// Reset grid
	for (int x = 0; x < view_maxsize; x++)
	{
		for (int y = 0; y < view_maxsize; y++)
		{
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}
}

void View::plot(GameObject *ptr)
{
	int ix;
	int iy;
	// If location is within grid
	if (get_subscripts(ix, iy, ptr->get_location()))
	{
		// Check if location is occupied
		if (grid[ix][iy][0] != '.')
		{
			grid[ix][iy][0] = '*';
			grid[ix][iy][1] = ' ';
		}
		else
		{
			ptr->drawself(grid[ix][iy]);
		}
	}
}

void View::draw()
{
	// Draw grid
	for (int y = (size - 1); y >= 0; y--)
	{
		// y-index number on every other row
		if ((y%(int)scale) == 0)
			cout << setw(2) << left << (y * scale);
		else
			cout << "  "; // Leading spaces

		for (int x = 0; x < size; x++)
		{
			cout << grid[x][y][0];
			cout << grid[x][y][1];
		}
		
		cout << endl;
	}

	// x-indeces
	cout << "  ";
	for (int i = 0; i < size; i++)
	{
		if ((i%(int)scale) == 0)
			cout << setw(4) << left << i * scale;
	}
	
	cout << left << endl;
}

bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
	// Distance to location
	CartVector dist_to;
	dist_to = (location - origin);

	// scale to the current grid size
	dist_to = dist_to/scale;

	// extract x and y grid indeces
	ix = (int)dist_to.x;
	iy = (int)dist_to.y;

	// Error check
	if (ix < 0 || iy < 0 || ix > size || iy > size)
	{
		cout << "An object is outside the display\n";
		return false;
	}
	else
		return true;
}