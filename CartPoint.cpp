// CartPoint.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include <iostream>
#include <cmath>
#include "CartPoint.h"
#include "CartVector.h"
using namespace std;

// Default constructor sets x and y to 0
CartPoint::CartPoint()
{
	x = 0.0;
	y = 0.0;
}

// Constructor that passes values to x and y
CartPoint::CartPoint(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

// Overload cout operator for "cout << p1"
ostream& operator<<(ostream &out, CartPoint& p1)
{
    out << "(" << p1.x << ", " << p1.y << ")";
    return out;
}

// Overload + operator for  "p1 + v1"
CartPoint operator+(CartPoint p1, CartVector v1)
{
	return CartPoint(p1.x + v1.x, p1.y + v1.y);
}

// Overload - operator for "p1 - p2"
CartVector operator-(CartPoint p1, CartPoint p2)
{
	return CartVector(p1.x - p2.x, p1.y - p2.y);
}

// Overload == operator for p1 == p2
bool operator==(CartPoint p1, CartPoint p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

// Obtain the shortest using pythagorean theorem
double cart_distance(CartPoint p1, CartPoint p2)
{
	double temp1 = p2.x - p1.x;
	double temp2 = p2.y - p1.y;

	temp1 = (temp1*temp1) + (temp2*temp2);
	temp1 = sqrt(temp1);

	return temp1;
}

// Return true if p1 == p2, else false
bool cart_compare(CartPoint p1, CartPoint p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	return false;
}
