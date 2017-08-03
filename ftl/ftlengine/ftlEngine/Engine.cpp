#include "Engine.hpp"
#include "Application.hpp"
#include "Timer.hpp"
#include "Input.hpp"
#include "Graphics.hpp"
#include "Object.hpp"
#include "GameLogic.hpp"
#include "Factory.hpp"
#include "Physics.hpp"

#include "..\..\examples\ftlgame\PlayerController.hpp"

#include <iostream>



SWE::Engine::Engine(bool /*debugMode_*/) : GameIsRunning(true),
dt(0), pm_fixeddt(1/60.f), pm_accumulator(0), pm_accumulatorlock(0.25f)
{
								
				
				//ENGINE = this;
		//Add systems to the engine
				Application::instance(); // 0
				ObjectFactory::instance(); //1
				GameLogic::instance(); //2
				Physics::instance(); //3
				Graphics::instance(); //4
				

				//Initialize systems after being added
/*				for (auto & sys : SystemsList) {
								sys->Initialize();
				}*/

				Input::instance();
				//Initialize Timer
				Timer::instance();
}

SWE::Engine::~Engine()
{
}

void SWE::Engine::GameLoop()
{

				//Testing Object creation. Delete afterwards
				Object* asteroid = ObjectFactory::instance()->CreateAsteroid(Vector3(0,0,0),Vector3(0,0,0), 1.f);
				asteroid;
				Object* player = ObjectFactory::instance()->CreatePlayer(Vector3(0,0,0),Vector3(0,0,0), 1.f);
				player;

				while (GameIsRunning) {
								//Update the dt
								//Calculayte the amount of time took for one iteration in prvious frame.
								dt = Timer::instance()->GetDelta();
								pm_accumulator += dt;

								//To prevent spiral of death; just a user defined random number.
								if (pm_accumulator > pm_accumulatorlock) {
												pm_accumulator = pm_accumulatorlock;
								}

								//Update all systems
								/*for (auto & sys: SystemsList) {
												sys->Update(dt);
								}*/
								//for (int i = 0; i < 3/*3 is the index for the physics
								//																						  Todo : Implement GetSystem function, whether it's templatized or...*/
								//				; ++i) {
								//				SystemsList[i]->Update(dt);
								//}
								Application::instance()->Update(dt);
								ObjectFactory::instance()->Update(dt);
								GameLogic::instance()->Update(dt);

								while (pm_accumulator >= pm_fixeddt) {
												Physics::instance()->Update(pm_accumulator);
												pm_accumulator -= pm_fixeddt;
								}
								//Have to implement linear interpolation, for the smooth game feels.
								Graphics::instance()->Update(pm_accumulator);

				}
				//ObjectFactory::instance()->DestroyAllObjects();
				//When Engine Shutsdown
				ObjectFactory::instance()->DestroyAllObjects();
}


//void SWE::Engine::AddSystem(System* system)
//{
//				//Add a system to the Engine to be updated every frame
//				SystemsList.push_back(system);
//}


void SWE::Engine::Quit()
{
				GameIsRunning = false;
}

