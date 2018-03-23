
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
extern bool canMove;
extern bool quit;
extern bool win;
#endif