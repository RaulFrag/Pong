#include <iostream>
#include <string>
#include "SDL.h"
#include "General.h"

using namespace std;

int main(int argr, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Pong",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_W, SCREEN_H,
		SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window);

	while (true)
	{
		
	}
	return 0;
}