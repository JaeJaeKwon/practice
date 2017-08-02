#include "Controller.hpp"
#include "GameLogic.hpp"

SWE::Controller::Controller() : Component(ComponentType::CT_CONTROLLER) {
				myController =
								GameLogic::instance()->ControllerList.insert(
												GameLogic::instance()->ControllerList.end(), this);
}

SWE::Controller::~Controller() {
				GameLogic::instance()->ControllerList.erase(myController);
}
