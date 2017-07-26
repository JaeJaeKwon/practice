#include "Input.hpp"
#include "DebugUtil.hpp"
#include <bitset>

namespace {
				//Container of keys pressed 
				std::bitset<SDL_NUM_SCANCODES> s_pressed;
				//Container of keys triggered
				std::bitset<SDL_NUM_SCANCODES> s_triggered;
				//Container of keys released 
				std::bitset<SDL_NUM_SCANCODES> s_released;
}

void SWE::Input::Initialize()
{
				for (int i = 0; i < SDL_NUM_SCANCODES; ++i){
								s_pressed[i] = s_triggered[i] = s_released[i] = false;
				}
}

void SWE::Input::Reset()
{
			for (int i = 0; i < SDL_NUM_SCANCODES; ++i){
								s_triggered[i] = s_released[i] = false;
				}
}

void SWE::Input::SetKeyPressed(SDL_Scancode key_, SDL_EventType keyStatus_)
{
				DEBUG_ASSERT(key_ < SDL_SCANCODE_UNKNOWN || key_>SDL_NUM_SCANCODES,
								"KeyError");

				if (keyStatus_ == SDL_KEYDOWN) {
								s_pressed[key_] = true;
								s_triggered[key_] = true;
				}
				else if (keyStatus_ == SDL_KEYUP) {
								s_released[key_] = true;
								s_pressed[key_] = false;
				}
}

bool SWE::Input::IsPressed(SDL_Scancode key_)
{
				return s_pressed[key_];
}

bool SWE::Input::IsTriggered(SDL_Scancode key_)
{
				return s_triggered[key_];
}

bool SWE::Input::IsReleased(SDL_Scancode key_)
{
				return s_released[key_];
}

bool SWE::Input::IsAnyPressed()
{
				return s_pressed.any();
}

bool SWE::Input::IsAnyTriggered()
{
				return s_triggered.any();
}

bool SWE::Input::IsAnyReleased()
{
				return s_released.any();
}
