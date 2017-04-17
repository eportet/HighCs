// Merchant.cpp
// PA4 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: December 10, 2015

#include <iostream>
#include <fstream>
#include "Merchant.h"
#include "GameObject.h"
#include "Dock.h"
#include "Model.h"

//				//
// CONSTRUCTORS //
//				//

// Default constructor sets everything to initial values
Merchant::Merchant(Model* model) : Sailor('M', model)
{
	size = 10;
	recruit_timer = 0;
}

// Default constructor sets everything to initial values and the display code
Merchant::Merchant(int in_id, Dock* in_hideout, Model* in_model) : Sailor('M', in_id, in_hideout, in_model)
{
	size = 10;
	recruit_timer = 0;
}

//					//
// MEMBER FUNCTIONS //
//					//

double Merchant::get_speed()
{
	return Sailor::get_speed();
}

// Starts recruiting
bool Merchant::start_recruiting(Merchant* sailor_mate)
{
	
	if (   (this->hideout == sailor_mate->hideout) && (hideout->get_berths() >= 10) 
		&& (health >=40 && health <=60) && (sailor_mate->get_health() >= 40 
		&&  sailor_mate->get_health() <= 60) && (world->merchants_at(hideout) == 2))
	{					
		//cout << display_code << get_id() << ": I found a new recruit!" << endl;
		this->state = 'r';
		sailor_mate->recruit();
		return true;
	}
	return false;
}

void Merchant::recruit()
{
	state = 'r';
}

void Merchant::srecruit()
{
	state = 'a';
}

// returns true if an event happens
bool Merchant::update()
{

	if(is_hidden() && state == 'a')
	{
		
		for (std::list<Sailor*>::iterator itSailor = world->sailor_ptrs.begin(); itSailor != world->sailor_ptrs.end(); itSailor++)
		{
			if ((*itSailor)->get_display_code() == 'M')
				start_recruiting(dynamic_cast<Merchant*>(*itSailor));
		}
	}

	else if (state == 'r')
	{
		recruit_timer++;
		if(world->merchants_at(hideout)>2)
		{
			cout << "Rats! Another merchant drove away our new recruit!" << endl;
			state = 'a';
			recruit_timer = 0;
			return true;
		}
		else if (recruit_timer == 2)
		{
			state = 'a';

			dynamic_cast<Merchant*>(recruit_partner)->srecruit();

			int newID = world->get_merch_id();

			cout << display_code << get_id() << ": I found a new recruit!\n";

			Merchant* new_merch = new Merchant(newID, hideout, world);
			world->add_new_object(new_merch);

			recruit_timer = 0;
		}
		else
		{
			//cout << display_code << get_id() << ": Recruiting..." << endl;
		}
		return true;
	}

	return Sailor::update();
}

void Merchant::show_status()
{
	//cout << "DID IT GET HERE?\n";
	cout << "Merchant status: ";
	GameObject::show_status();
	switch (state)
	{
		case 'a':
			if (is_hidden())
			{
				cout << " is anchored (and hiding). Has a size of: " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
				break;
			}
			cout << " is anchored. Has a size of: " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
			break;

		case 'h':
			cout << " is going to hide at Dock " << hideout->get_id() << endl;
			break;

		case 's':
			cout << " Has a speed of: " << get_speed() << " and is heading to: " << destination << endl;
			break;

		case 'o':
			cout << " is outbound to Port: " << port->get_id() << " with a speed of " << get_speed() << endl;
			break;

		case 'i':
			cout << " is inbound to Dock: " << dock->get_id() << " with a speed of " << get_speed() << endl;
			break;

		case 'l':
			cout << " is supplying at Port " << port->get_id() << endl;
			break;

		case 'u':
			cout << " is unloading at Dock " << dock->get_id() << endl;
			break;

		case 'd':
			cout << " is docked at Dock " << dock->get_id() << endl;
			break;

		case 't':
			cout << " is in trouble " << get_id() << endl;
			break;

		case 'r':
			cout << " is recruiting a merchant with M" << recruit_partner->get_id() << ".\n";
			break;

		default:
			break;
	}
}

// GameSaves
void Merchant::save(ofstream& file)
{
	Sailor::save(file);
	file << recruit_timer;
	
	if (recruit_partner == NULL)
		file << -1;
	else
		file << recruit_partner->get_id();
}

void Merchant::restore(ifstream& file, Model& model)
{
	int partner_id;

	Sailor::restore(file, model);
	file >> recruit_timer >> partner_id;

	if (partner_id == -1)
		recruit_partner = NULL;
	else
		recruit_partner = (*world).get_Merchant_ptr(partner_id);
}







