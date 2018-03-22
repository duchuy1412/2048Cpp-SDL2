
#ifndef APPGAME_H_
#define APPGAME_H_H

#include "draw.h"

class Application
{
public:
	Application();
	
	~Application();

	int randomNumber();

	void CreateRandomCard();

	bool isFullBoard();

	bool isLose();

	bool doDown();

	bool doUp();

	bool doRight();

	bool doLeft();

	void handleInput();

private:
	
};

#endif