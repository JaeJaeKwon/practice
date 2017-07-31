#pragma once
/*
Input.hpp
HeeJae Kwon
*/
#include "MyInput.hpp"
#include <bitset>
#include <memory>

namespace SWE {

				class Input
				{
				public:
								friend class Application;
																								//Magical singletern code
								  static Input* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<Input> instance(new Input());
            return instance.get();
        }
										~Input();
								//void Initialize();
								void Reset();

								//Check if a specific key is
								bool IsPressed(Key_Scancode key)const;
								bool IsTriggered(Key_Scancode key)const;
								bool IsReleased(Key_Scancode key)const;

								bool IsAnyPressed()const;
								bool IsAnyTriggered()const;
								bool IsAnyReleased()const;

				private:
										Input();
								void SetKeyPressed(Key_Scancode key, Key_EventType keyStatus);

								//Sets pressed, triggered, released, or unpressed status of a key

												//Container of keys pressed 
				std::bitset<Key_NUM_SCANCODES> s_pressed;
				//Container of keys triggered
				std::bitset<Key_NUM_SCANCODES> s_triggered;
				//Container of keys released 
				std::bitset<Key_NUM_SCANCODES> s_released;

				};

}