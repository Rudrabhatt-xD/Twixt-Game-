#ifndef LINKS_H
#define LINKS_H

#include "twixt.h"

void init_links();
bool chk_clinks(int x1, int y1, int x2, int y2, char color);
void a_link(int x, int y, char color);
bool link_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

#endif
