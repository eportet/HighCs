// GameCommand.h
// PA3 EC327 Fall 2015
// Name: Eduardo Portet
// BUID: U8049227
// Date: November 21, 2015

#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Model.h"

// Command functions
void do_go_command(Model&);
void do_run_command(Model&);
void do_list_command(Model&);
void do_sail_command(Model&);
void do_port_command(Model&);
void do_hide_command(Model&);
void do_dock_command(Model&);
void do_anchor_command(Model&);
void do_plunder_command(Model&);
void do_new_command(Model&);
void do_save_command(Model&);
void do_restore_command(Model&);

#endif