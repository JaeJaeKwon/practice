#include "Engine.hpp"
#include "Application.hpp"

namespace SWE {

				//Engine* ENGINE;
}

SWE::Engine::Engine(bool /*debugMode_*/) : GameIsRunning(true)
{
				//ENGINE = this;
}

SWE::Engine::~Engine()
{
}

void SWE::Engine::GameLoop()
{
				//Initialize Timer

				while (GameIsRunning) {
								//Update the dt

								//Update all systems
								for (auto & sys: SystemsList) {
												sys->Update(dt);
								}

				}
				//When Engine Shutsdown
}

void SWE::Engine::DestroyAllSystems()
{
				//Delete all systems (in reverse) that they were added in
				//to minimize dependency problems between systems
				//for (auto & sys : SystemsList) {
				//				delete sys;
				//}
}

void SWE::Engine::AddSystem(System* system)
{
				//Add a system to the Engine to be updated every frame
				SystemsList.push_back(system);
}

void SWE::Engine::Initialize()
{
				//Add systems to the engine
				AddSystem(Application::instance());

				//Initialize systems after being added
				for (auto & sys : SystemsList) {
								sys->Initialize();
				}
}

void SWE::Engine::Quit()
{
				GameIsRunning = false;
}

