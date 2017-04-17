// CartVector.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef CARTVECTOR_H
#define CARTVECTOR_H
#include <iostream>
using namespace std;

class CartVector
{
public:
	double x, y;

	CartVector();
	CartVector(double, double);

	friend ostream& operator<< (ostream &out, CartVector &v1);
	friend CartVector operator* (CartVector v1, double d);
	friend CartVector operator/ (CartVector v1, double d);
};

#endif