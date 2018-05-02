
#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <SDL.h>
#include <SDL_ttf.h>

//const int size_array = 4;
extern int width, height;
extern int cards[4][4];
extern int score;
extern int highScore;
extern bool quit;
extern bool win;


//TEXT-FONT-SIZE
const int FONT_SIZE_TINY = 15;
const int FONT_SIZE_SMALL = 25;
const int FONT_SIZE_NORMAL = 35;
const int FONT_SIZE_MEDIUM = 45;
const int FONT_SIZE_BIG = 50;
const int FONT_SIZE_GREAT = 70;

//COLOR
const SDL_Color COLOR_TEXT = {41,57,85};
const SDL_Color COLOR_LOGO = {126, 120, 114};
const SDL_Color COLOR_NUM_1 = {119,110,101};
const SDL_Color COLOR_NUM_2 = {249, 246, 242};
const SDL_Color COLOR_0 = {205,193,180};
const SDL_Color COLOR_2 = {238, 228, 218};
const SDL_Color COLOR_4 = {237, 224, 200};
const SDL_Color COLOR_8 = {242, 177, 121};
const SDL_Color COLOR_16 = {245, 149, 99};
const SDL_Color COLOR_32 = {246, 124, 95};
const SDL_Color COLOR_64 = {246, 94, 59};
const SDL_Color COLOR_128 = {237, 207, 114};
const SDL_Color COLOR_256 = {237, 204, 97};
const SDL_Color COLOR_512 = {237, 200, 80};
const SDL_Color COLOR_1024 = {237, 197, 63};
const SDL_Color COLOR_2048 = {237, 194, 46};

#endif GLOBALVARS_H_