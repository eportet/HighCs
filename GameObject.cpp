// GameObject.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "GameObject.h"
#include "Model.h"
#include <iostream>

using namespace std;

//				//
// CONSTRUCTORS //
//				//

GameObject::GameObject()
{
	display_code = '0';
	state = '0';
	id_num = 0;
	cout << "GameObject default constructed" << endl;
}

// Default constructor sets location to (0,0)
GameObject::GameObject(char in_code, int in_id)
{
	display_code = in_code;
	id_num = in_id;
	location = CartPoint();
	cout << "GameObject default constructed" << endl;
}

// Constructor initializes location to desired value
GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	cout << "GameObject constructed" << endl;
}

// Destructor
GameObject::~GameObject()
{
	cout << "GameObject destructed\n";
}

//					//
// MEMBER FUNCTIONS //
//					//

// Returns the location of object
CartPoint GameObject::get_location()
{
	return location;
}

// Returns the id of object
int GameObject::get_id()
{
	return id_num;
}

// Outputs the information of the object
void GameObject::show_status()
{
	cout << display_code << " with ID " << get_id() << " at location " << location;
}

void GameObject::drawself(char* grid)
{
	// Assign display code
	*grid = display_code;

	if (id_num > 10)
		// Cannot display entire ID number
		*(grid + 1) = '+'; // '+' means the ID is > 10
	else
	{
		// convert integer id_num to ASCII character equivalent
		char char_id = (char)(id_num + (int)'0');

		*(grid + 1) = char_id;
	}
}



