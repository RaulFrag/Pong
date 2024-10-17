#include "Ball.h"
#include <cstdlib>
#include <ctime>

Ball::Ball()
{
	ball.h = 0;
	ball.w = 0;
	ball.x = 0;
	ball.y = 0;
	dir = 0;
}

Ball::~Ball()
{
}

void Ball::init()
{
	dir = rand() % 4 + 1;
}

void Ball::update()
{
}

void Ball::render()
{
}
