#pragma once
#include "Points.h"
#include "SDL.h"

class Ball
{
	SDL_Rect ball;
	int dir;
	int ballWaitToStart;

public:
	Ball();
	~Ball();

	void resetBall();

	void init();
	void update();
	void render(SDL_Surface* screenSurface);
};

