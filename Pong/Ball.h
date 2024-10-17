#pragma once
#include "SDL.h"

class Ball
{
	bool p1;
	bool p2;
	SDL_Rect ball;
	int dir;
	int ballWaitToStart;

public:
	Ball();
	~Ball();

	void tocaParedP1();
	void tocaParedP2();
	void resetP();

	bool getP1();
	bool getP2();

	void resetBall();

	void init();
	void update();
	void render(SDL_Surface* screenSurface);
};

