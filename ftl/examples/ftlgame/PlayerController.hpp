#pragma once
#include "Controller.hpp"
#include "vector3.hpp"

namespace SWE {
				class Transform;
				class Rigidbody;
				class PlayerController : public Controller
				{
				public:
								PlayerController();
								~PlayerController();

								void Initialize() override;
								void Update(float dt) override;


				private:
								void Movement(float dt);
								void Experience(float dt);

								int health;
								unsigned int experience;
								float expTimer;
								//Vector3 pos;

								Transform* pTransform;
								Rigidbody* pRigidbody;

				};
}