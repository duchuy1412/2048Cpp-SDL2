
#include "draw.h"


void draw_game::draw_label(const char * font, const int& size, const int r, const int g, const int b, const char * text, int x, int y, SDL_Renderer* renderer ){
	TTF_Font * fonts = TTF_OpenFont(font, size);
	SDL_Color color = {r,g,b};
	int texW = 200;
	int texH = 200;
	SDL_Surface * surface = TTF_RenderText_Solid(fonts, text , color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);	
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { x, y, texW, texH };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	//freesurface
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(fonts);
}

void draw_game::draw_grid(){
    SDL_Event event;
	TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *  window = SDL_CreateWindow("2048",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 650, SDL_WINDOW_SHOWN);    
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);    
	
	/*Set color background*/
	SDL_SetRenderDrawColor(renderer, 205, 193, 180, 255);
	SDL_RenderClear(renderer);
	
	

	int top = 200, left = 50, step = 100, w = 10, h = 410;
	int left_label = 250, top_label = 30;

	SDL_Rect grid_vertical;
	grid_vertical.x = left;
	grid_vertical.y = top;
	grid_vertical.w = w;
	grid_vertical.h = h;
	
	SDL_Rect grid_horizontal;
	grid_horizontal.x = left;
	grid_horizontal.y = top;
	grid_horizontal.w = h;
	grid_horizontal.h = w;

	
	//Label
	SDL_Rect label_1;
	label_1.x = left_label;
	label_1.y = top_label;
	label_1.w = 100;
	label_1.h = 60;

	SDL_Rect label_2;
	label_2.x = left_label + label_1.w + 10;
	label_2.y = top_label;
	label_2.w = 100;
	label_2.h = 60;

	SDL_Rect newgame;
	newgame.x = 300;
	newgame.y = 120;
	newgame.w = 150;
	newgame.h = 40;

	/*color line*/
	SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
	int i;
	/*draw grid*/
	for(i = 0; i <= 400; i = i + 100)
	{
		SDL_RenderFillRect(renderer, &grid_vertical);
		grid_vertical.x += 100;
	}

	for(i = 0; i <= 400; i = i + 100)
	{
		SDL_RenderFillRect(renderer, &grid_horizontal);
		grid_horizontal.y += 100;
	}
	
	/*draw label*/
	SDL_RenderFillRect(renderer, &label_1);
	SDL_RenderFillRect(renderer, &label_2);
	SDL_SetRenderDrawColor(renderer,143,122,102, 255); // color button new game
	SDL_RenderFillRect(renderer, &newgame);

	/*Logo Game*/
	draw_label("fonts.ttf", 70, 126, 120, 114, "2048", 50, 50, renderer);

	/*Label Score*/
	draw_label("fonts.ttf", 15, 238,228,218, "Score", label_1.x+30, label_1.y+5, renderer);
	draw_label("fonts.ttf", 15, 238,228,218, "Best", label_2.x+35, label_2.y+5, renderer);

	/*Score*/
	std::stringstream ss; ss << score;
	draw_label("times.ttf", 24, 255,255,255, ss.str().c_str(), label_1.x+58-ss.str().length()*10, label_1.y+25, renderer);

	std::stringstream ss1; ss1 << highScore;
	draw_label("times.ttf", 24, 255,255,255, ss1.str().c_str(), label_2.x+55-ss1.str().length()*10, label_2.y+25, renderer);

	draw_label("fonts.ttf", 24, 255,255,255, "New game", newgame.x + 15, newgame.y + 5, renderer);

	SDL_Rect tile[4][4];
	tile[0][0].x = 60;
	tile[0][0].y = 210;
	tile[0][0].w = 90;
	tile[0][0].h = 90;

	int TileStep = 100;

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{	
			tile[i][j].x = tile[0][0].x + i*TileStep;
			tile[i][j].y = tile[0][0].y + j*TileStep;
			tile[i][j].w = tile[0][0].w;
			tile[i][j].h = tile[0][0].h;
			
		}
	}
	

	//render
	SDL_RenderPresent(renderer);

	while (!quit)
    {
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
								//
								std::cout << "new game";
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

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}
