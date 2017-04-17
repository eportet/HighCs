// GameCommand.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "GameCommand.h"
#include <iostream>

using namespace std;

int ID;
int ID1;
int ID2;
double x;
double y;

//					 //
// COMMAND FUNCTIONS //
//					 //

// Call start_sailing funtion of sailor
void do_sail_command(Model &model)
{
	cin >> ID >> x >> y;
	CartPoint cdest = CartPoint(x,y);
	cout << "Sailing " << ID << " to " << cdest << endl;
	model.get_Sailor_ptr(ID)->start_sailing(CartPoint(x, y));
}

// Call start_supplying function of sailor from port
void do_port_command(Model &model)
{
	cin >> ID1 >> ID2;
	cout << "Sailor " << ID1 << " supplying at Port " << ID2 << " and going to Port " << ID2 << endl;
	model.get_Sailor_ptr(ID1)->start_supplying(model.get_Port_ptr(ID2));
}

// Call start_docking function of sailor to dock
void do_dock_command(Model &model)
{
	cin >> ID1 >> ID2;
	cout << "Sailor " << ID1 << " sailing to Dock " << ID2 << endl;
	model.get_Sailor_ptr(ID1)->start_docking(model.get_Dock_ptr(ID2));
}

// Call start_hiding funtion of sailor
void do_hide_command(Model &model)
{
	cin >> ID;
	cout << "Sailor " << ID << " hiding " << ID << endl;
	model.get_Sailor_ptr(ID)->start_hiding();
}

void do_anchor_command(Model &model)
{
	cin >> ID;
	cout << "Stopping " << ID << endl;
	model.get_Sailor_ptr(ID)->anchor();
}

void do_go_command(Model &model)
{
	cout << "Advancing time one tick\n";

	model.update();

	model.show_status();
}

void do_run_command(Model &model)
{
	cout << "Advancing to next event or 5 ticks\n";
	
	for (int i = 0; i < 5; ++i)
	{
		if (model.update())
			break;
	}

	model.show_status();
}

void do_list_command(Model &model)
{
	model.show_status();
}

