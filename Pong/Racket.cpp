#include "Racket.h"

void Racket::setRa_1Y(int y)
{
	if (y == -1)
	{
		if (ra_1.y > 0)
		{
			ra_1.y += y;
		}
	}
	else
	{
		if (ra_1.y < SCREEN_H - ra_1.h)
		{
			ra_1.y += y;
		}
	}
}

void Racket::setRa_2Y(int y)
{
	if (y == -1)
	{
		if (ra_2.y > 0)
		{
			ra_2.y += y;
		}
	}
	else
	{
		if (ra_2.y < SCREEN_H - ra_2.h)
		{
			ra_2.y += y;
		}
	}
}

Racket::Racket()
{
	ra_1.x = 0;
	ra_1.y = 0;
	ra_1.w = 0;
	ra_1.h = 0;

	ra_2.x = 0;
	ra_2.y = 0;
	ra_2.w = 0;
	ra_2.h = 0;
}

Racket::~Racket()
{
}

void Racket::init()
{
	ra_1.x = 100;
	ra_1.y = 220;
	ra_1.w = 10;
	ra_1.h = 85;

	ra_2.x = 900;
	ra_2.y = 220;
	ra_2.w = 10;
	ra_2.h = 85;
}

void Racket::update(int ejeJY, bool up, bool down)
{
	int joy_y = 0;
	int key_y = 0;
	if (ejeJY >= 5000)
	{
		joy_y = 1;
	}
	else
	{
		if (ejeJY <= -5000)
		{
			joy_y = -1;
		}
	}
	if (up == true)
	{
		key_y = -1;
	}
	if (down == true)
	{
		key_y = 1;
	}
	setRa_1Y(joy_y);
	setRa_2Y(key_y);
}

void Racket::render(SDL_Surface* screenSurface)
{
	SDL_FillRect(screenSurface, &ra_1, 0xffffff);
	SDL_FillRect(screenSurface, &ra_2, 0xffffff);
}
