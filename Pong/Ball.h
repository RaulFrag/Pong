#pragma once
#include "SDL.h"
class Ball
{
public:
	Ball();
	~Ball();

	void init();
	void update();
	void render();

	SDL_Rect ball;
};

