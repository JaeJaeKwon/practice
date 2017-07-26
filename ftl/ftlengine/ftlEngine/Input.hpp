#pragma once
/*
Input.hpp
HeeJae Kwon
*/
#include <SDL.h>

namespace SWE {

				class Input
				{
				public:
								static void Initialize();
								static void Reset();

								//Sets pressed, triggered, released, or unpressed status of a key
								static void SetKeyPressed(SDL_Scancode key, SDL_EventType keyStatus);

								//Check if a specific key is
								static bool IsPressed(SDL_Scancode key);
								static bool IsTriggered(SDL_Scancode key);
								static bool IsReleased(SDL_Scancode key);

								static bool IsAnyPressed();
								static bool IsAnyTriggered();
								static bool IsAnyReleased();

				private:

				};

}