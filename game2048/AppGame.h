
#ifndef APPGAME_H_
#define APPGAME_H_H

#include "globalvars.h"
#include "draw.h"

class Application
{
public:
	int randomNumber();

	bool isFull();

	void generateNumber();

	void Down();

	void Up();

	void Right();

	void Left();

private:
	bool lose;
};

#endif