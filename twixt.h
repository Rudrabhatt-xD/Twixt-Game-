#ifndef TWIXT_H
#define TWIXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>



extern char arr[25][25];
extern bool links[25][25][8];
extern char l_color[25][25][8];
extern int l_count;
extern int k_moves[8][2];

void init_game();
void display_board(char arr[25][25]);
bool valid_move(int x, int y, char color,int turn);
void place_pin(int x, int y, char color);


#endif