
#include "globalvars.h"
#include "draw.h"

Game* ptrGame = nullptr;

int main(int argv, char* argo[]){   
	//Create window
	ptrGame = new Game("2048", 500, 650);
	
	//check best score
	ptrGame->checkbestScore();

	//draw board game
	ptrGame->draw_grid();
	

	//loop game
	while(!quit){
		//request user
		ptrGame->handleEvent();
		
		//

	}
	ptrGame->close();
	return 0;
}
