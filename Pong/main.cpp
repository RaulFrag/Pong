#include <iostream>
#include <string>
#include "SDL.h"
#include <cstdlib>
#include <ctime>
#include "General.h"
#include "Ball.h"

using namespace std;

int main(int argr, char* args[]) {
	srand(time(NULL));
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;


	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Pong",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_W, SCREEN_H,
		SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window);

	Ball pelota;

	pelota.init();

	while (true)
	{
		pelota.update();
	
		pelota.render(screenSurface);
		
		SDL_UpdateWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, 0x000000);
	}
	return 0;
}