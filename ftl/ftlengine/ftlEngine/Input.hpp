#pragma once
/*
Input.hpp
HeeJae Kwon
*/
#include <SDL.h>
#include <bitset>
#include <memory>

namespace SWE {

				class Input
				{
				public:
																								//Magical singletern code
								  static Input* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<Input> instance(new Input());
            return instance.get();
        }
										~Input();
								//void Initialize();
								void Reset();

								//Sets pressed, triggered, released, or unpressed status of a key
								void SetKeyPressed(SDL_Scancode key, SDL_EventType keyStatus);

								//Check if a specific key is
								bool IsPressed(SDL_Scancode key)const;
								bool IsTriggered(SDL_Scancode key)const;
								bool IsReleased(SDL_Scancode key)const;

								bool IsAnyPressed()const;
								bool IsAnyTriggered()const;
								bool IsAnyReleased()const;

				private:
										Input();
												//Container of keys pressed 
				std::bitset<SDL_NUM_SCANCODES> s_pressed;
				//Container of keys triggered
				std::bitset<SDL_NUM_SCANCODES> s_triggered;
				//Container of keys released 
				std::bitset<SDL_NUM_SCANCODES> s_released;

				};

}