/*
Engine.hpp
HeeJae Kwon
Defines the Engine class
*/
#pragma once

#include "System.hpp"
#include <vector>
#include <memory>

namespace SWE {

				//The engine manage all systems in the game, updating them, routing msgs,
				//and destroy the systems when the game ends
				class Engine
				{
				public:
								//Magical singletern code
								  static Engine* instance(bool debugMode_ = false)  //!< Returns an instance of the class
        {
            static std::unique_ptr<Engine> instance(new Engine(debugMode_));
            return instance.get();
        }
								~Engine();

								//Update all systems
								void GameLoop();
								//Destroy all systems in the engine in reverse to avoid dependency issues
								void DestroyAllSystems();
								//Add systems to the engine
								void AddSystem(System* system);
								//Initialize Engine
								void Initialize();

								void Quit();

								//Todo: System Message functions

				private:
								//Hide Constructor
								Engine(bool debugMode_ = false);
								//Track all systems the engine uses
								std::vector<System*> SystemsList;
								//Main loop
								bool GameIsRunning;
								//delta for each frame
								float dt;

				};

				//A global pointer of the instance of the Engine
				//extern Engine* ENGINE;

} //namespace SWE end