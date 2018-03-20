
#ifndef DRAW_H_
#define DRAW_H_

#include "globalvars.h"

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event event;
	SDL_Rect grid_vertical[5]; //grid
	SDL_Rect grid_horizontal[5]; //grid
	SDL_Rect label_1; //button score
	SDL_Rect label_2; //button highscore
	SDL_Rect newgame; //button new game
	SDL_Rect tile[4][4];

	void draw_grid();
	void draw_label(const char * font, const int& size, SDL_Color color, const char * text, int x, int y, SDL_Renderer* renderer);
	void handleEvent();
	void close();
	void checkbestScore();
	void newGame();
private:
};

#endif DRAW_H_