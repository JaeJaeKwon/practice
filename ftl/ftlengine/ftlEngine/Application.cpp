#include "Application.hpp"
#include "DebugUtil.hpp"
#include "Engine.hpp"
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
				//APP = this;
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
				
}

SWE::Application::~Application()
{
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
								SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
				);


				if (!pWindow) {
								DEBUG_ASSERT(pWindow == nullptr, "window is failed!");
				}
}

void SWE::Application::Update(float /*dt*/)
{
				//Todo: PollEvents
				PollEvents();
}


void SWE::Application::PollEvents()
{
				while (SDL_PollEvent(&event)) {
								PollWindowEvent(event);
								//PollKey
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

/*void SWE::Application::PollKeyboardEvent(SDL_Event & currEvent)
{
}

void SWE::Application::PollMouseEvent(SDL_Event & currEvent)
{
}
*/