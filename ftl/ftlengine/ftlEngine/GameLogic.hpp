#pragma once
/*
GameLogic.hpp
HeeJae Kwon

GameLogic will make sure that all logic in all objects are updated per frame
*/

#include "System.hpp"
#include "DebugUtil.hpp"

#include <memory>
#include <list>

namespace SWE {
				class Controller;
				class GameLogic : public System
				{
				public:
																//Magical singletern code
								  static GameLogic* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<GameLogic> instance(new GameLogic());
            return instance.get();
        }

								~GameLogic();

								void Initialize() override;
								void Update(float dt) override;

								std::list<Controller*> ControllerList;
				private:
								GameLogic();
								//List of Controller components

				};

}
