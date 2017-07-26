#pragma once
/*
Application.hpp
HeeJae Kwon
*/
#include <SDL.h>
#include "System.hpp"
#include <memory>

namespace SWE {
				class Application : public System
				{
				public:

									//Magical singletern code
								  static Application* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<Application> instance(new Application());
            return instance.get();
        }

								~Application();

								void Initialize() override;
								void Update(float dt) override;

								//Todo: add other features
								//Resolution size
								//Window size
								//Get and Set Window size
								//Fullscreen


				private:
								//Hide
								Application();

								void PollEvents();
								void PollWindowEvent(SDL_Event& currEvent);
								void PollKeyboardEvent(SDL_Event& currEvent);
								void PollMouseEvent(SDL_Event& currEvent);

								int screenWidth;
								int screenHeight;
								SDL_Event event;					//Events frome the OS
								SDL_Window* pWindow; //window data
				};

//				extern Application* APP;

}