// PA4.cpp
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include "InputHandling.h"
#include <iostream>

using namespace std;

//				//
// MAIN PROGRAM //
//				//

int main()
{
	// Header file
	cout << "EC327: Introduction to Software Engineering\nFall 2015\nProgramming Assignment 3\n";

	// Initiazlize
	Model model;
	View view;

	// Initial game status
	model.show_status();
	model.display(view);

	bool running = true;

	// MAIN PROGRAM LOOP
	while (running)
	{
		char cmd;
		
		cout << "Enter command: ";
		cin >> cmd;

		try
		{
			switch (cmd)
			{
				case 's':
					do_sail_command(model);
					break;
				case 'p':
					do_port_command(model);
					break;
				case 'a':
					do_anchor_command(model);
					break;
				case 'd':
					do_dock_command(model);
					break;
				case 'h':
					do_hide_command(model);
					break;
				case 'g':
					do_go_command(model);
					break;
				case 'r':
					do_run_command(model);
					break;
				case 'u':
					do_plunder_command(model);
					break;
				case 'n':
					do_new_command(model);
					break;
				case 'S':
					do_save_command(model);
					break;
				case 'R':
					do_restore_command(model);
					break;
				case 'l':
					do_list_command(model);
					break;
				case 'q':
					cout << "Terminating Program\n";
					running = false;
					break;
				default:
					cout << "Unknown command\n";
					return 0;
			}
		}
		catch (InvalidInput& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
			cin.clear() ;
			cin.ignore();
		}

		model.display(view);
	}
	// END MAIN PROGRAM LOOP
	
	return 0;
}