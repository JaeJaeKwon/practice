#pragma once
/*
Controller.hpp
HeeJae Kwon
*/

#include "Component.hpp"
#include <list>


namespace SWE {
				class Controller : public Component
				{
				public:
								Controller();
								~Controller();

								virtual void Initialize() {}
								virtual void Update(float /*dt*/) {}

								std::list<Controller*>::iterator myController;
				private:

				};

}