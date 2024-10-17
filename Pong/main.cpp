#include <iostream>
#include <string>
#include "SDL.h"
#include "General.h"
#include "Racket.h"

using namespace std;

SDL_GameController* findController()
{
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i))
		{
			return SDL_GameControllerOpen(i);
		}
	}

	return nullptr;
}

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

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
	{
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_GameController* mando = findController();

	if (mando == nullptr)
	{
		cout << "No hay mandos" << endl;
	}

	struct joystick
	{
		Sint16 y;
	};
	joystick ejeJ;
	ejeJ.y = 0;

	bool up = false;
	bool down = false;

	Racket raqueta;
	raqueta.init();
	bool endgame = false;
	while (!endgame)
	{
		SDL_Event test_event;
		while (SDL_PollEvent(&test_event)) {
			switch (test_event.type) {
			case SDL_QUIT:
				endgame = true;
				break;

			case SDL_CONTROLLERAXISMOTION:
				if (test_event.caxis.axis == 1)
				{
					ejeJ.y = test_event.caxis.value;
				}
				break;

			case SDL_KEYUP:
				if (test_event.key.keysym.scancode == SDL_SCANCODE_UP)
				{
					up = false;
				}
				if (test_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
				{
					down =false;
				}
				break;

			case SDL_KEYDOWN:
				if (test_event.key.keysym.scancode == SDL_SCANCODE_UP)
				{
					up = true;
				}
				if (test_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
				{
					down = true;
				}
				break;

			default:
				break;
			}
		}

		std::cout << ejeK.y << endl;
		raqueta.update(ejeJ.y, up, down);

		raqueta.render(screenSurface);
		SDL_UpdateWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, 0x000000);
	}
	return 0;
}