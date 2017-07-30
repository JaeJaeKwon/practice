#include "Input.hpp"
#include "DebugUtil.hpp"

using namespace SWE;

//namespace {
//				//Container of keys pressed 
//				std::bitset<SDL_NUM_SCANCODES> s_pressed;
//				//Container of keys triggered
//				std::bitset<SDL_NUM_SCANCODES> s_triggered;
//				//Container of keys released 
//				std::bitset<SDL_NUM_SCANCODES> s_released;
//}

Input::Input()
{
			for (int i = 0; i < SDL_NUM_SCANCODES; ++i){
								s_pressed[i] = s_triggered[i] = s_released[i] = false;
				}
}

Input::~Input()
{
}


void Input::Reset()
{
			for (int i = 0; i < SDL_NUM_SCANCODES; ++i){
								s_triggered[i] = s_released[i] = false;
				}
}

void Input::SetKeyPressed(SDL_Scancode key_, SDL_EventType keyStatus_)
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

bool Input::IsPressed(SDL_Scancode key_)const
{
				return s_pressed[key_];
}

bool Input::IsTriggered(SDL_Scancode key_)const
{
				return s_triggered[key_];
}

bool Input::IsReleased(SDL_Scancode key_)const
{
				return s_released[key_];
}

bool Input::IsAnyPressed()const
{
				return s_pressed.any();
}

bool Input::IsAnyTriggered()const
{
				return s_triggered.any();
}

bool Input::IsAnyReleased()const
{
				return s_released.any();
}
