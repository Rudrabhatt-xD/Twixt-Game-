#ifndef WIN_H
#define WIN_H

#include <stdbool.h>
#include "twixt.h"
#include "links.h"


bool check_win(char color);
void print_reachable_pins(char color);
bool verify_path_exists(char color);

#endif