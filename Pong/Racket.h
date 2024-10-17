#pragma once
#include "General.h"
#include "SDL.h"

class Racket
{
	SDL_Rect ra_1;
	SDL_Rect ra_2;

	void setRa_1Y(int y);

	void setRa_2Y(int y);

public:
	Racket();
	~Racket();

	void init();
	void update(int ejeJY, bool up, bool down);
	void render(SDL_Surface* screenSurface);

	int getRa_1X() { return ra_1.x; };
	int getRa_1Y() { return ra_1.y; };
	int getRa_1H() { return ra_1.h; };

	int getRa_2X() { return ra_2.x; };
	int getRa_2Y() { return ra_2.y; };
	int getRa_2H() { return ra_2.h; };
};

