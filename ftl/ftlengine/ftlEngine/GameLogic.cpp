#include "GameLogic.hpp"
#include "Controller.hpp"

using namespace SWE;
GameLogic::GameLogic()
{

}

GameLogic::~GameLogic()
{
}

void GameLogic::Initialize()
{
}

void GameLogic::Update(float dt)
{
				for (auto  &  element : ControllerList) {
								element->Update(dt);
				}
}
