// CartVector.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include <iostream>
#include <cmath>
#include "CartVector.h"
using namespace std;

// Default constructor sets x and y to 0
CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

// Constructor that passes values to x and y
CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

// Overload cout operator for "cout << p1"
ostream& operator<< (ostream &out, CartVector &v1)
{
    out << "<" << v1.x << ", " << v1.y << ">";
    return out;
}

CartVector operator* (CartVector v1, double d)
{
	return CartVector(v1.x*d, v1.y*d);
}

CartVector operator/ (CartVector v1, double d)
{
	return CartVector(v1.x/d, v1.y/d);
}