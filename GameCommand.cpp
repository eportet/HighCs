// GameCommand.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include <exception>
#include <iostream>
#include <fstream>
#include "GameCommand.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Dock.h"
#include "Model.h"
#include "Sailor.h"
#include "Port.h"
#include "InputHandling.h"
#include "Pirate.h"
#include "Merchant.h"

using namespace std;

int ID;
int ID1;
int ID2;
char TYPE;
double x;
double y;

//					 //
// COMMAND FUNCTIONS //
//					 //

// Call start_sailing funtion of sailor
void do_sail_command(Model& model)
{
	if (!(cin >> ID))
		throw InvalidInput("Was expecting an integer");
	
	if (!(cin >> x >> y))
		throw InvalidInput("Was expecting a double");

	Sailor* sailor = model.get_Sailor_ptr(ID);

	if (sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");

	CartPoint cdest = CartPoint(x,y);
	cout << "Sailing " << ID << " to " << cdest << endl;

	sailor->start_sailing(cdest);
}

// Call start_supplying function of sailor from port
void do_port_command(Model& model)
{
	if (!(cin >> ID1 >> ID2))
		throw InvalidInput("Was expecting an integer");

	cout << "Sailor " << ID1 << " supplying at Port " << ID2 << " and going to Port " << ID2 << endl;

	Sailor* sailor = model.get_Sailor_ptr(ID1);
	if (sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	
	Port* port = model.get_Port_ptr(ID2);
	if (port == (Port*)NULL)
		throw InvalidInput("Invalid Port ID");

	sailor->start_supplying(port);
}

// Call start_docking function of sailor to dock
void do_dock_command(Model& model)
{
	if (!(cin >> ID1 >> ID2))
		throw InvalidInput("Was expecting an integer");

	cout << "Sailor " << ID1 << " sailing to Dock " << ID2 << endl;
	
	Sailor* sailor = model.get_Sailor_ptr(ID1);
	if (sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");

	Dock* dock = model.get_Dock_ptr(ID2);
	if (dock == (Dock*)NULL)
		throw InvalidInput("Invalid Dock ID");

	sailor->start_docking(dock);

}

// Call start_hiding funtion of sailor
void do_hide_command(Model& model)
{
	if (!(cin >> ID))
		throw InvalidInput("Was expecting an integer");

	Sailor* sailor = model.get_Sailor_ptr(ID);

	cout << "Sailor " << ID << " hiding " << sailor->hideout->get_id() << endl;
	
	sailor->start_hiding();
}

void do_anchor_command(Model& model)
{
	if (!(cin >> ID))
		throw InvalidInput("Was expecting an integer");
	
	cout << "Stopping " << ID << endl;
	Sailor* sailor = model.get_Sailor_ptr(ID);
	
	if (sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	
	sailor->anchor();
}

void do_plunder_command(Model& model)
{
	if (!(cin >> ID1 >> ID2))
		throw InvalidInput("Was expecting an integer");

	Sailor* sailor1 = model.get_Sailor_ptr(ID1);
	if (sailor1 == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");

	Sailor* sailor2 = model.get_Sailor_ptr(ID2);
	if (sailor2 == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");

	sailor1->start_plunder(sailor2);
}

void do_go_command(Model& model)
{
	cout << "Advancing time one tick\n";

	model.update();

	model.show_status();
}

void do_run_command(Model& model)
{
	cout << "Advancing to next event or 5 ticks\n";
	
	for (int i = 0; i < 5; ++i)
	{
		if (model.update())
			break;
	}

	model.show_status();
}

void do_list_command(Model& model)
{
	model.show_status();
}

void do_new_command(Model& model)
{
	Model* in_model = &model;

	cin >> TYPE;
		
	if (TYPE != 'P' && TYPE != 'D' && TYPE != 'M' && TYPE!= 'R')
		throw InvalidInput("Invalid type");
	if (!(cin >> ID1))
		throw InvalidInput("Was expecting an integer");
	
	// Make Pirate
	if (TYPE == 'R')
	{
		Sailor* sailor = model.get_Sailor_ptr(ID1);
		if (sailor != (Sailor*)NULL)
			throw InvalidInput ("Duplicate ID");
		else
		{
			Pirate* pirate = new Pirate(ID1, in_model);
			model.add_new_object(pirate);
		}
	}

	// Make Merchant
	else if (TYPE == 'M')
	{
		if(!(cin >> ID2))
			throw InvalidInput("Was expecting an integer");
		
		Sailor* sailor = model.get_Sailor_ptr(ID1);
		if (sailor != (Sailor*)NULL)
			throw InvalidInput("Duplicate ID");
		
		Dock* dock = model.get_Dock_ptr(ID2);
		if (dock == (Dock*)NULL)
			throw InvalidInput("Dock ID invalid!");
		
		Merchant* merchant = new Merchant(ID1, dock, in_model);
		model.add_new_object(merchant);
	}

	// Make Dock
	else if (TYPE == 'D')
	{
		if (!(cin >> x >> y))
			throw InvalidInput("Was expecting a double");
		
		Dock* dock = model.get_Dock_ptr(ID1);
		if (dock != (Dock*)NULL)
			throw InvalidInput("Duplicate ID");
		else
		{
			Dock* dock = new Dock(ID1, CartPoint(x, y));
			model.add_new_object(dock);
		}
	}

	// Make Port
	else
	{
		if (!(cin >> x >> y))
			throw InvalidInput("Was expecting a double");
		
		Port* port = model.get_Port_ptr(ID1);
		if (port != (Port*)NULL)
			throw InvalidInput ("Duplicate ID");
		else
		{
			Port* port = new Port(ID1, CartPoint(x, y));
			model.add_new_object(port);
		}
	}
}

void do_save_command(Model& model)
{
    //Input file name
    string filename;
    cin >> filename;
    const char* filer = filename.c_str();
   
    //cout << filer;
    ofstream file;
    file.open(filer);

    //Call save functions
    model.save(file);

    file.close();
}

void do_restore_command(Model& model)
{
	string filename;
	cin >> filename;
	const char* filer = filename.c_str();
	ifstream file(filer);
	if (file.is_open())
	{
		model.restore(file);
		file.close();
	}
	else
		throw InvalidInput ("Restore file doesn't exist");
		
}

