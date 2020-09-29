// The file "SDL2.dll" should be copied from a previous SDL 
// into same folder as source.cpp file is.
#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char* argv[])
{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
			cout << "SDL initialization failed. SDL Error: " << SDL_GetError();}
		else	{ cout << "SDL initialization succeeded!";}

	SDL_Window* myWindow = NULL;
	SDL_Renderer* myRenderer = NULL;
	bool done = false;

	SDL_CreateWindowAndRenderer(1600, 900, SDL_RENDERER_ACCELERATED | SDL_WINDOW_FULLSCREEN_DESKTOP, &myWindow, &myRenderer);
	SDL_Event myEvent;
	
	while (!done) {
		
		while (SDL_PollEvent(&myEvent)) {
			
			if (myEvent.type == SDL_QUIT)
			{
				done = true;
				break;
			}

			if (myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_ESCAPE) {
				done = true;
				break;
			}
		};

		SDL_SetRenderDrawColor(myRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(myRenderer);
		SDL_SetRenderDrawColor(myRenderer, 0x00, 0x00, 0xff, 0xff);
		SDL_RenderDrawLine(myRenderer, 5, 5, 1595, 5);
		SDL_RenderDrawLine(myRenderer, 5, 5, 5, 895);
		SDL_RenderDrawLine(myRenderer, 1595, 5, 1595, 895); 
		SDL_RenderDrawLine(myRenderer, 5, 895, 1595, 895);
		
		SDL_RenderPresent(myRenderer);
	}

	SDL_Quit();
	cin.get();
	return 0;
}