
#include "globalvars.h"
#include "draw.h"

Game* ptrGame = nullptr;

int main(int argv, char* argo[]){   
	ptrGame = new Game("2048", 500, 650);
	ptrGame->draw_grid();
	while(!quit){
		ptrGame->handleEvent();
	}
	ptrGame->close();
	return 0;
}
