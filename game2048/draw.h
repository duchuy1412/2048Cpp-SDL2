
#ifndef DRAW_H_
#define DRAW_H_

#include "globalvars.h"

const int FONT_SIZE_TINY = 15;
const int FONT_SIZE_SMALL = 25;
const int FONT_SIZE_NORMAL = 35;
const int FONT_SIZE_MEDIUM = 45;
const int FONT_SIZE_BIG = 50;
const int FONT_SIZE_GREAT = 70;

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	void draw_grid();
	void handleEvent();
	void render();
	void checkBestScore();
	void saveBestScore();
	void info(const char * txt); //result game
	void newGame();
	void close();
private:
	void draw_label(const char * font, const int& size, SDL_Color color, const char * text, int x, int y, SDL_Renderer* renderer);
	void paint_tile(int& i, int& j, const char * text, const int font_size, SDL_Color color_bg, SDL_Color color);
	void updateScore();
	
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event event;
	SDL_Rect grid_vertical[5]; //grid
	SDL_Rect grid_horizontal[5]; //grid
	SDL_Rect newgame; //button new game
	SDL_Rect tile[4][4];
};

#endif DRAW_H_