
#ifndef DRAW_H_
#define DRAW_H_

#include "globalvars.h"

class draw_game
{
public:
	void draw_grid();
	void draw_label(const char * font, const int& size, const int r, const int g, const int b, const char * text, int x, int y, SDL_Renderer* renderer);
	void checkbestScore();
};

#endif DRAW_H_