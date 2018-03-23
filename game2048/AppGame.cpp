
#include "AppGame.h"
#include "draw.h"
#include "globalvars.h"

Application::Application()
{
	//create cards to begin Game
	CreateRandomCard();

	CreateRandomCard();
}

Application::~Application()
{

}

int Application::randomNumber()
{
	int a=rand()%20;
	if (!a) return 4;	//generate 4: 5%
	else return 2;		//generate 2: 95%
}

void Application::CreateRandomCard()
{
	int i = rand()%4, j = rand()%4;
	if (cards[i][j]==0){
		int number = randomNumber();
		cards[i][j] = number;
	}
	else{
		CreateRandomCard();
	}
}

bool Application::isFullBoard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (cards[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Application::isLose()
{
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (cards[i][j]==cards[i][j+1] || cards[i][j]==cards[i+1][j]){
				canMove = true;
			}
		}
	}
	if ( isFullBoard() && !canMove) {
		return true;
	}
	return false;
}


void Application::handleInput()
{
	SDL_Event e;
	SDL_WaitEvent(&e);
	switch(e.key.keysym.sym){
		case SDLK_UP: 
			std::cout << "up" << std::endl;
			doUp();
			break;
		case SDLK_DOWN:
			std::cout << "down" << std::endl;
			doDown();
			break; 
		case SDLK_LEFT: 
			std::cout << "left" << std::endl;
			doLeft();
			break;
		case SDLK_RIGHT: 
			std::cout << "right" << std::endl;
			doRight();
			break;
		case SDLK_ESCAPE:
			quit = true;
			break;
		default:
			break;
	}
}

bool Application::doUp()
{
    bool isDo = false;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int x1 = x + 1; x1 < 4; x1++)
            {
                if (cards[y][x1] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y][x1];
                        cards[y][x1] = 0;
                        x--;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y][x1])
                    {
                        cards[y][x] *= 2;
                        cards[y][x1] = 0;
						score += cards[y][x];
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if(isDo){
        CreateRandomCard();
	}
    return isDo;
}

bool Application::doDown()
{
    bool isDo = false;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 3; x >= 1; x--)
        {
            for (int x1 = x - 1; x1 >= 0; x1--)
            {
                if (cards[y][x1] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y][x1];
                        cards[y][x1] = 0;
                        x++;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y][x1])
                    {
                        cards[y][x] *= 2;
						score += cards[y][x];
                        cards[y][x1] = 0;
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if (isDo)
		CreateRandomCard();
    return isDo;
}

bool Application::doLeft()
{
    bool isDo = false;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int y1 = y + 1; y1 < 4; y1++)
            {
                if (cards[y1][x] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y1][x];
                        cards[y1][x] = 0;
                        y--;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y1][x])
                    {
                        cards[y][x] *= 2;
						score += cards[y][x];
                        cards[y1][x] = 0;
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if (isDo)
        CreateRandomCard();
    return isDo;
}

bool Application::doRight()
{
    bool isDo = false;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 3; y >= 1; y--)
        {
            for (int y1 = y - 1; y1 >= 0; y1--)
            {
                if (cards[y1][x] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y1][x];
                        cards[y1][x] = 0;
                        y++;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y1][x])
                    {
                        cards[y][x] *= 2;
						score += cards[y][x];
                        cards[y1][x] = 0;
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if (isDo)
        CreateRandomCard();
    return isDo;
}
