#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif // 


#include <Windows.h>
#include <iostream>
#include "ftl.hpp"

#include "SDL.h"
/*
int WINAPI WinMain(HINSTANCE, HINSTANCE , LPSTR, int) {
				SDL_Init(SDL_INIT_VIDEO);

				return 0;
}
*/

//int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
int main(int, char**) {
				//debug
				DEBUG_MEMORY_LECHECKS();
				DEBUG_CREATE_CONSOLE();


				if (SDL_Init(SDL_INIT_VIDEO) < 0) {

				}

				SDL_Window* pWindow = SDL_CreateWindow(
				"ftlgame",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								1280,
								720,
								SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE
				);


				if (pWindow) {
								DEBUG_ASSERT(pWindow == nullptr, "window is failed!");
				}
				else {
								DEBUG_PRINT("Window is created\n");
				}

				SDL_DestroyWindow(pWindow);
				pWindow = nullptr;


				SDL_Quit();

				//debug
				DEBUG_DESTROY_CONSOLE();


				return 0;
}