// CartPoint.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef CARTPOINT_H
#define CARTPOINT_H
#include <iostream>
#include "CartVector.h"
using namespace std;

class CartPoint
{
public:
	double x, y;

	CartPoint();
	CartPoint(double, double);

	friend ostream& operator<<(ostream &out, CartPoint& p1);
	friend CartPoint operator+(CartPoint p1, CartVector v1);
	friend CartVector operator-(CartPoint p1, CartPoint p2);
};

double cart_distance (CartPoint, CartPoint);
bool cart_compare (CartPoint, CartPoint);

#endif