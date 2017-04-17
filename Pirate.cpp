// Pirate.cpp
// PA4 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: December 10, 2015

#include <fstream>
#include "Pirate.h"
#include "Sailor.h"
#include "Model.h"
#include "Dock.h"
#include "CartPoint.h"

using namespace std;

Pirate::Pirate(Model* model): Sailor('R', model)
{
	state = 'a';
	attack_strength = 2;
	range = 1;
	target = NULL;
	health = 25;
}

Pirate::Pirate(int in_id, Model* in_model): Sailor('R', in_id, (*in_model).gen_location(), in_model)
{
	state = 'a';
	attack_strength = 2;
	range = 1;
	target = NULL;
	health = 25;
}

double Pirate::get_speed()
{
	return 0;
}

void Pirate::start_plunder(Sailor* target)
{
	if (target->is_alive() && is_alive())
	{
		CartPoint loc_target = (*target).get_location();
	    CartPoint loc_self = location;
	    double distance = cart_distance(loc_target, loc_self);
	    if (distance <= 1)
	    {
	        cout << get_display_code() << get_id() << ": Arrrggghhhh!" << endl;
	        state = 'p';
	        this->target = target;
	    }
	    else
	        cout << get_display_code() << get_id() << ": I will be back for you!\n";
	}
}

void Pirate::start_recruiting(Sailor* sailor_mate)
{
	cout << "My primary goal is to plunder merchants\n";
}

bool Pirate::update()
{
	switch (state)
	{
		case 'x':
		case 'a':
			return false;

		case 'p':
			CartPoint loc_target = target->get_location();
			CartPoint loc_self = location;
			double distance = cart_distance(loc_target, loc_self);
			if (distance > range)
			{
				cout << get_display_code() << get_id() << ": Darn! It escaped.\n";
				state = 'a';
				target = NULL;
				return true;
			}
			else
			{
				if (!(*target).is_alive())
				{
					cout << get_display_code() << get_id() << ": I triumph!\n";
					state = 'a';
					health = health + 5;
					return true;
				}
				else
				{
					target->get_plundered(attack_strength);
					cout << get_display_code() << get_id() << ": Arrghh matey!\n";
					return false;
				}
			}
    }
    return false;		
}

void Pirate::show_status()
{
	cout << "Pirate status: ";
	GameObject::show_status();
	switch (state)
	{
		case 'a':
			cout << " is anchored. Has a size of: " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
			break;
		case 'p':
			cout << " Currently attacking " << target->get_id() << endl;
			break;
		case 'x':
			break;
	}
}

// GameSaves
// void Pirate::save(ofstream& file)
// {
//     Sailor::save(file);
//     file << attack_strength << range;

//     if (target == NULL)
//     	file << -1;
//     else
//     	file << target->get_id();
// }

// void Pirate::restore(ifstream& file, Model& model)
// {
// 	int target_id;

// 	Sailor::restore(file, model);
// 	file >> attack_strength >> range >> target_id;

// 	if (target_id == -1)
// 		target = NULL;
// 	else
// 		target = world->get_Sailor_ptr(target_id);
// }



