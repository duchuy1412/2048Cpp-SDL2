
#include "AppGame.h"

Game* ptrGame = nullptr;
Application* app = nullptr;

int main(int argv, char* argo[]){
	srand(static_cast<unsigned int>(time(NULL)));

	//Create window
	ptrGame = new Game("2048", width, height);

	app = new Application();
	
	replay:
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
		
		if (app->isLose() == true)
			{
				ptrGame->info("YOU LOSE!");
				ptrGame->newGame();
				SDL_Delay(3000);
				goto replay;
			}

		if(win){
				ptrGame->info("YOU WIN!");
				ptrGame->newGame();
				SDL_Delay(5000);
				goto replay;
		}		
		
	}

	ptrGame->close();
	return 0;
}
