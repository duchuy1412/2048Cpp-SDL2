
#include "AppGame.h"

Game* ptrGame = nullptr;
Application* app = nullptr;

int main(int argv, char* argo[]){
	srand(static_cast<unsigned int>(time(NULL)));

	//Create window
	ptrGame = new Game("2048", width, height);
	app = new Application();
	
	//check best score
	ptrGame->checkBestScore();

	//draw board game
	ptrGame->draw_grid();

	//loop game
	while(!quit){
		//request user
		ptrGame->handleEvent();
		
		//input user
		app->handleInput();
		
		//update
		ptrGame->render();

		ptrGame->saveBestScore();

		if (app->isLose())
			{
				ptrGame->info("YOU LOSE!");
			}

		if(win){
				ptrGame->info("YOU WIN!");
			}
	}

	
		

	ptrGame->close();
	return 0;
}
