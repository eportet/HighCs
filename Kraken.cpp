// Kraken.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "Kraken.h"
#include <iostream>

using namespace std;

Kraken::Kraken() : GameObject('K', 0)
{}

void Kraken::sweep_away(Model& model)
{
	int i = 0;
	timer = model.get_time();

	//Print message 5 seconds before
	if (timer%15 == 10)
		cout << "Early Kraken warning!\n";
	
	if (timer%15 == 0 && timer != 0)
	{
		for (std::list<Sailor*>::iterator it = model.sailor_ptrs.begin(); it != model.sailor_ptrs.end(); ++it)
		{
			char sailor_state = (**it).get_state();
			if (sailor_state != 'u' && sailor_state != 'd' && sailor_state != 't' && !((**it).is_hidden()))
			{
				int sailor_id = (**it).get_id();
				char sailor_code = (**it).get_display_code();
				swept_id[i] = sailor_id;
				swept_code[i] = sailor_code;
				cout << "Kraken swept away " << sailor_code << sailor_id << endl;
				if (sailor_code == 'M')
				{
					for (std::list<Sailor*>::iterator itSailor = model.sailor_ptrs.begin(); itSailor != model.sailor_ptrs.end(); ++itSailor)
					{
						int merchantID = (**itMerchant).get_id();
						if (sailor_id == merchantID)
							itSailor = model.sailor_ptrs.erase(itSailor);
					}
				}
				it = model.sailor_ptrs.erase(it);
				it--;
				i++;
			}
		}
	}
}

bool Kraken::update()
{}

void Kraken::show_status()
{}

