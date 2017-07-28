#pragma once
/*
Controller.hpp
HeeJae Kwon
*/

#include "Component.hpp"
#include "GameLogic.hpp"
#include <list>


namespace SWE {
				class Controller : public Component
				{
				public:
								Controller() : Component(ComponentType::CT_CONTROLLER) {
												myController =
																GameLogic::instance()->ControllerList.insert(
																GameLogic::instance()->ControllerList.end(), this);
								}
								~Controller() {GameLogic::instance()->ControllerList.erase(myController);}

								virtual void Initialize() {}
								virtual void Update(float /*dt*/) {}

								std::list<Controller*>::iterator myController;
				private:

				};

}