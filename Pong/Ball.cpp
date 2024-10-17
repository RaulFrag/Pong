#include "Ball.h"
#include <cstdlib>
#include <ctime>
#include "General.h"

Ball::Ball()
{
	ball.h = 0;
	ball.w = 0;
	ball.x = 0;
	ball.y = 0;
	dir = 0;
	ballWaitToStart = 0;
}

Ball::~Ball()
{
}

void Ball::resetBall()
{
	dir = rand() % 4 + 1;
	ball.x = SCREEN_W / 2;
	ball.y = SCREEN_H / 2;
	ballWaitToStart = 300;
}

void Ball::init()
{
	dir = rand() % 4 + 1;
	ball.x = SCREEN_W / 2;
	ball.y = SCREEN_H / 2;
	ball.w = 25;
	ball.h = 25;
}

void Ball::update()
{
	if (ballWaitToStart > 0)
	{
		ballWaitToStart--;
	}
	else
	{
		switch (dir)
		{
		case 1:
			ball.x++;
			ball.y--;
			if (ball.x >= (SCREEN_W - ball.w))
			{
				resetBall();
			}
			if (ball.y <= 0)
			{
				dir = 2;
			}
			break;
		case 2:
			ball.x++;
			ball.y++;
			if (ball.x >= (SCREEN_W - ball.w))
			{
				resetBall();
			}
			if (ball.y >= (SCREEN_H - ball.h))
			{
				dir = 1;
			}
			break;
		case 3:
			ball.x--;
			ball.y++;
			if (ball.x <= 0)
			{
				resetBall();
			}
			if (ball.y >= (SCREEN_H - ball.h))
			{
				dir = 4;
			}
			break;
		case 4:
			ball.x--;
			ball.y--;
			if (ball.x <= 0)
			{
				resetBall();
			}
			if (ball.y <= 0)
			{
				dir = 3;
			}
			break;
		default:
			break;
		}
	}
}

void Ball::render(SDL_Surface* screenSurface)
{
	SDL_FillRect(screenSurface, &ball, 0xFFFFFF);
}

