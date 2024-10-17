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
	p1 = 0;
	p2 = 0;
}

Ball::~Ball()
{
}

void Ball::tocaParedP1()
{
	p1 = true;
}

void Ball::tocaParedP2()
{
	p2 = true;
}

void Ball::resetP()
{
	p1 = false;
	p2 = false;
}

bool Ball::getP1()
{
	return p1;
}

bool Ball::getP2()
{
	return p2;
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
				tocaParedP1();
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
				tocaParedP1();
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
				tocaParedP2();
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
				tocaParedP2();
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

