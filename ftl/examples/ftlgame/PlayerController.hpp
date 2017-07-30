#pragma once
#include "Controller.hpp"
#include "vector3.hpp"
#include <iostream>

namespace SWE {
				class Transform;
				class PlayerController : public Controller
				{
				public:
								PlayerController();
								~PlayerController();

								void Initialize() override;
								void Update(float dt) override;


				private:
								void Movement();
								void Experience(float dt);

								int health;
								unsigned int experience;
								float expTimer;
								Vector3 pos;

								Transform* pTransform;

				};
}