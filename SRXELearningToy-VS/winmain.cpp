#include <SDL.h>
#include <Windows.h>

#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 136

int SDL_main(int argc, char* argv[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return -1;
	}
	else
	{
		window = SDL_CreateWindow(
			"SRXELearningToy",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			MessageBox(nullptr, L"Window could not be created!", L"Error", MB_OK);
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
			SDL_UpdateWindowSurface(window);

			//for (;;) {
			//}

			SDL_Delay(2000);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}
