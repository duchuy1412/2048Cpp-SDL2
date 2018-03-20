
#include "draw.h"


SDL_Color COLOR_TEXT = {238,228,218};
SDL_Color COLOR_LOGO = {126, 120, 114};
SDL_Color COLOR_NUM_1 = {119,110,101};
SDL_Color COLOR_NUM_2 = {249, 246, 242};


Game::Game(const char* title, int width, int height)
{
	TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);  
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Game::~Game()
{

}

void Game::draw_label(const char * font, const int& size, SDL_Color color, const char * text, int x, int y, SDL_Renderer* renderer ){
	TTF_Font * fonts = TTF_OpenFont(font, size);
	int texW = 20;
	int texH = 20;
	SDL_Surface * surface = TTF_RenderText_Blended(fonts, text, color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);	
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { x, y, texW, texH };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	//freesurface
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(fonts);
}

void Game::draw_grid(){
	/*Set color background*/
	SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
	SDL_RenderClear(renderer);

	int top = 200, left = 50;
	int left_label = 250, top_label = 30;

	/*Draw Label*/
	label_1.x = left_label;
	label_1.y = top_label;
	label_1.w = 100;
	label_1.h = 60;

	label_2.x = left_label + label_1.w + 10;
	label_2.y = top_label;
	label_2.w = 100;
	label_2.h = 60;
	//draw shape
	SDL_SetRenderDrawColor(renderer,156,201,245,255);
	SDL_RenderFillRect(renderer, &label_1);
	SDL_RenderFillRect(renderer, &label_2);
	//Score
	
	draw_label("fonts.ttf", FONT_SIZE_TINY, COLOR_TEXT , "Score", label_1.x+30, label_1.y+5, renderer);
	draw_label("fonts.ttf", FONT_SIZE_TINY, COLOR_TEXT, "Best", label_2.x+35, label_2.y+5, renderer);


	/*color grid*/
	SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
	int i;
	/*draw grid*/
	int grid_x = 50, grid_y = 200, step = 100;

	for(i = 0; i <= 5; i++)
	{
		grid_vertical[i].x = grid_x + i*step;
		grid_vertical[i].y = grid_y;
		grid_vertical[i].w = 10;
		grid_vertical[i].h = 410;

		SDL_RenderFillRect(renderer, &grid_vertical[i]);
	}

	for(i = 0; i <= 5; i++)
	{
		grid_horizontal[i].x = grid_x;
		grid_horizontal[i].y = grid_y + i*step;
		grid_horizontal[i].w = 410;
		grid_horizontal[i].h = 10;

		SDL_RenderFillRect(renderer, &grid_horizontal[i]);
	}


	/*Button New Game*/
	SDL_SetRenderDrawColor(renderer,143,122,102, 255); // color button new game
	
	newgame.x = 300;
	newgame.y = 120;
	newgame.w = 150;
	newgame.h = 40;

	SDL_RenderFillRect(renderer, &newgame);
	draw_label("fonts.ttf", FONT_SIZE_SMALL, COLOR_NUM_2, "New game", newgame.x + 15, newgame.y + 5, renderer);


	/*Logo Game*/
	draw_label("fonts.ttf", FONT_SIZE_GREAT, COLOR_LOGO, "2048", 50, 50, renderer);

	

	/*Score*/
	//std::stringstream ss; ss << score;

	//const char * text = ss.str().c_str();
	//draw_label("times.ttf", 24, 255,255,255, text, label_1.x+58-ss.str().length()*10, label_1.y+25, renderer);
	
	//std::stringstream ss1; ss1 << highScore;

	//const char * text1 = ss1.str().c_str();
	//draw_label("times.ttf", 24, 255,255,255, text1, label_2.x+55-ss1.str().length()*10, label_2.y+25, renderer);



	/*Draw tiles*/
	int _x = left+10, _y = top+10;

	int _Step = 100, _w = 90, _h = 90; //tile 90x90

	SDL_SetRenderDrawColor(renderer,205,193,180,0); 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{	
			tile[i][j].x = _x + i*_Step;
			tile[i][j].y = _y + j*_Step;
			tile[i][j].w = _w;
			tile[i][j].h = _h;
				
			SDL_RenderFillRect(renderer, &tile[i][j]);
		}
	}
	draw_label("fonts.ttf", FONT_SIZE_BIG, COLOR_NUM_1, "2", 90, 225, renderer);

	//render
	SDL_RenderPresent(renderer);
}


void Game::handleEvent()
{

	//Event
	SDL_WaitEvent(&event);
		switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button==SDL_BUTTON_LEFT){
							int X=event.button.x;
							int Y=event.button.y;
							if (X>newgame.x && X < newgame.x + newgame.w && Y>newgame.y && Y < newgame.y + newgame.h){
								newGame();
							}
				}
				break;
			case SDL_MOUSEMOTION:
				int mouseX=event.motion.x;
				int mouseY=event.motion.y;
				if (mouseX>newgame.x && mouseX < newgame.x + newgame.w && mouseY>newgame.y && mouseY < newgame.y + newgame.h){
					SDL_Cursor* cursor;
					cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
					SDL_SetCursor(cursor);
				}
				else{
					SDL_Cursor* cursor;
					cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
					SDL_SetCursor(cursor);
				}
				break;
		}

}

void Game::newGame()
{
	std::cout << "\nnew game: tao chua lam OK";
}

void Game::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}