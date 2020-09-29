#include <SDL2/SDL.h>
#include <stdio>
#include <stdio.h>

int main(int argc, char* argv[]) {

	if (!SDL_Init(SDL_INIT_EVERYTHING))
		printf("Could not init SDL");

	getchar();
	return 0;

}