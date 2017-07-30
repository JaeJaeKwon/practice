#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif // 


#include <Windows.h>
#include <iostream>
#include <ftl.hpp>
#include <Engine.hpp>

#include <SDL.h>
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
				//Todo: Create Engine
				SWE::Engine* SWEngine = SWE::Engine::instance();

				//Todo: Initialize the Engine and initialize all systems
				//SWEngine->Initialize();


				//Todo: Create initiail game state, main menu

				//Todo: Main loop
				SWEngine->GameLoop();

				//Todo: Shutdown the Engine
				//Also means shutdown and clean all systems

				//Todo: Delete the Engine
				//SWEngine->DestroyAllSystems();


		


				//debug
				DEBUG_DESTROY_CONSOLE();


				return 0;
}