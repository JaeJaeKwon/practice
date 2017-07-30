#include "Engine.hpp"
#include "Application.hpp"
#include "Timer.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

#include "Object.hpp"
#include "GameLogic.hpp"

#include "..\..\examples\ftlgame\PlayerController.hpp"


#include <iostream>


namespace SWE {

				//Engine* ENGINE;
}

SWE::Engine::Engine(bool /*debugMode_*/) : GameIsRunning(true)
{
				//ENGINE = this;
		//Add systems to the engine
				AddSystem(Application::instance());
				AddSystem(GameLogic::instance());
				AddSystem(Graphics::instance());
				

				//Initialize systems after being added
				for (auto & sys : SystemsList) {
								sys->Initialize();
				}

				Input::instance();
				//Initialize Timer
				Timer::instance();
}

SWE::Engine::~Engine()
{
}

void SWE::Engine::GameLoop()
{
				//Input::instance();
				////Initialize Timer
				//Timer::instance();

				Object* test = new Object();
				test->AddComponent(new Transform());
				test->AddComponent(new PlayerController());
	/*			Transform* trans = static_cast<Transform*>(test->GetComponent(ComponentType::CT_TRANSFORM));
				std::cout << trans->GetPosition().x <<" " << trans->GetPosition().y <<" "<< trans->GetPosition().z;*/
				test->Initialize();
				while (GameIsRunning) {
								//Update the dt
								dt = Timer::instance()->GetDelta();

								//Update all systems
								for (auto & sys: SystemsList) {
												sys->Update(dt);
								}

				}
				delete test;
				//When Engine Shutsdown
}

//void SWE::Engine::DestroyAllSystems()
//{
//				//Delete all systems (in reverse) that they were added in
//				//to minimize dependency problems between systems
//				//for (auto & sys : SystemsList) {
//				//				delete sys;
//				//}
//}

void SWE::Engine::AddSystem(System* system)
{
				//Add a system to the Engine to be updated every frame
				SystemsList.push_back(system);
}

//void SWE::Engine::Initialize()
//{
//				//Add systems to the engine
//				AddSystem(Application::instance());
//				AddSystem(GameLogic::instance());
//				AddSystem(Graphics::instance());
//				
//
//				//Initialize systems after being added
//				for (auto & sys : SystemsList) {
//								sys->Initialize();
//				}
//}

void SWE::Engine::Quit()
{
				GameIsRunning = false;
}

