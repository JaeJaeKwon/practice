#include "Application.hpp"
#include "DebugUtil.hpp"
#include "Engine.hpp"
#include "Input.hpp"
/*
namespace SWE {
				Application* APP = nullptr;
}
*/

SWE::Application::Application() : screenWidth(800), 
																																		screenHeight(600), 
																																		pWindow(nullptr)
{
	//			DEBUG_ASSERT(APP != nullptr, "No more than 1 instance of Application");
			/*	//APP = this;
				if (SDL_Init(SDL_INIT_VIDEO) < 0) {
								DEBUG_PRINT("SDL couldn't initialize! SD_Error: %s\n", SDL_GetError());
				}

				pWindow = SDL_CreateWindow(
								"ftlgame",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								screenWidth,
								screenHeight,
								SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
				);


				if (!pWindow) {
								DEBUG_ASSERT(pWindow == nullptr, "window is failed!");
								*/
				
}

SWE::Application::~Application()
{
				SDL_GL_DeleteContext(glContext);

				SDL_DestroyWindow(pWindow);
				pWindow = nullptr;
				SDL_Quit();
}

void SWE::Application::Initialize()
{
				if (SDL_Init(SDL_INIT_VIDEO) < 0) {
								DEBUG_PRINT("SDL couldn't initialize! SD_Error: %s\n", SDL_GetError());
				}

				pWindow = SDL_CreateWindow(
								"ftlgame",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								screenWidth,
								screenHeight,
								SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL
				);
				
				SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

								DEBUG_ASSERT(pWindow == nullptr, "window is failed!");

							glContext =	SDL_GL_CreateContext(pWindow);
							/*
							check SDL_WINDOW_OPENGL or
							Graphics Driver suppoert the minor or major GL version
							Force GPU to use .exe file not on board Graphic!
							*/
								DEBUG_ASSERT(glContext == nullptr, "opengl is failed!");

}

void SWE::Application::Update(float /*dt*/)
{
				Input::instance()->Reset();
				//Todo: PollEvents
				PollEvents();

		/*		if (Input::IsAnyPressed()) {
								printf("AnyPressed\n");
				}
				if (Input::IsAnyTriggered()) {
								printf("AnyTriggered\n");
				}
				if (Input::IsAnyReleased()) {
								printf("AnyReleased\n");
				}
*/

}


void SWE::Application::PollEvents()
{
				while (SDL_PollEvent(&event)) {
								PollWindowEvent(event);
								PollKeyboardEvent(event);
								//PollMouse
				}
}

void SWE::Application::PollWindowEvent(SDL_Event & currEvent)
{
				switch (currEvent.type) {
				case SDL_QUIT: {
								Engine::instance()->Quit();
				}break;
				default:
								break;
				}
}

void SWE::Application::PollKeyboardEvent(SDL_Event & currEvent)
{
				switch (currEvent.type) {
				case SDL_KEYDOWN: {

								Input::instance()->SetKeyPressed(currEvent.key.keysym.scancode, SDL_KEYDOWN);

				}break;
				case SDL_KEYUP: {

								Input::instance()->SetKeyPressed(currEvent.key.keysym.scancode, SDL_KEYUP);

				}break;

				default:
								break;
				}
}

void SWE::Application::SwapWindow()
{
				SDL_GL_SwapWindow(pWindow);
}

/*void SWE::Application::PollMouseEvent(SDL_Event & currEvent)
{
}
*/