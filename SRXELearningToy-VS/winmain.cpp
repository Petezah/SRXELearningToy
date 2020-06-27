#include <SDL.h>
#include <Windows.h>

#include "idisplay.h"
#include "srxelearningtoy.h"

#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 136

class SDLDisplay : public IDisplay
{
public:
	SDLDisplay() = default;
	~SDLDisplay() { Uninitialize(); }

	bool Initialize()
	{
		if (_initialized) return true;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}
		else
		{
			_window = SDL_CreateWindow(
				"SRXELearningToy",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH,
				SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
			if (_window == nullptr)
			{
				MessageBox(nullptr, L"Window could not be created!", L"Error", MB_OK);
				SDL_Quit();
				return false;
			}
			else
			{
				_screenSurface = SDL_GetWindowSurface(_window);
			}
		}

		_initialized = true;
		return true;
	}

	void Uninitialize()
	{
		if (!_initialized) return;

		SDL_DestroyWindow(_window);
		SDL_Quit();
		_initialized = false;
	}

	void ClearDisplay(uint8_t r, uint8_t g, uint8_t b)
	{
		SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, r, g, b));
	}

	// IDisplay
	virtual void SetMode(DisplayMode mode) override
	{

	}

	virtual DisplayMode GetMode() override
	{
		return _mode;
	}

	virtual void SetPixel(uint8_t x, uint8_t y, uint8_t c) override
	{
		char* p = (char*)_screenSurface->pixels;
		char* pix = p + (_screenSurface->pitch * y) + (x * _screenSurface->format->BytesPerPixel);
		for (uint8_t i = 0; i < _screenSurface->format->BytesPerPixel; ++i)
		{
			*pix++ = c;
		}
	}

	virtual void Present() override
	{
		SDL_UpdateWindowSurface(_window);
	}

private:
	bool _initialized = false;
	SDL_Window* _window = nullptr;
	SDL_Surface* _screenSurface = nullptr;
	DisplayMode _mode = DisplayMode::Graphics1Bit;
};


int SDL_main(int argc, char* argv[])
{
	SDLDisplay display;
	if (!display.Initialize())
	{
		return -1;
	}

	SRXELearningToy::Instance()->Initialize(&display);
	display.Present();
	SDL_Delay(2000);

    return 0;
}
