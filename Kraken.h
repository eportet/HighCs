// Kraken.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef KRAKEN_H
#define KRAKEN_H

#include "Model.h"

class Kraken : GameObject
{
public:
	int timer;
	Kraken();
	bool update();
	void show_status();
	void sweep_away(Model&);
	void printout();
	int swept_id[30];
	char swept_chars[30];
};

#endif
