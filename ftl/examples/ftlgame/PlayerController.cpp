#include "PlayerController.hpp"
#include "Input.hpp"				
#include "Object.hpp"
#include "Transform.hpp"
#include "Rigidbody.hpp"

#include <iostream>

using namespace SWE;

PlayerController::PlayerController()
{
				health = 20;
				experience = 0;
				expTimer = 3.f;
				//pos.SetZero();
}

PlayerController::~PlayerController()
{
}

void PlayerController::Initialize()
{
				pTransform = static_cast<Transform*>(GetOwner()->GetComponent(CT_TRANSFORM));
				pRigidbody = static_cast<Rigidbody*>(GetOwner()->GetComponent(CT_RIGIDBODY));
}

void PlayerController::Update(float dt)
{
				Movement(dt);
				Experience(dt);
				if (Input::instance()->IsTriggered(Key_SCANCODE_F)) {
								--health;
				}
			//		pTransform->SetPosition(pos);

					std::cout << pTransform->GetPosition().x << ", " << pTransform->GetPosition().y << "\n";
}

void PlayerController::Movement(float dt)
{
				Input* pInput = Input::instance();
				if (pInput->IsPressed(Key_SCANCODE_W)) {
							pRigidbody->m_force += Vector3(0, 50.f*dt, 0);
								//pos.y += dt;
				}
				if (pInput->IsPressed(Key_SCANCODE_S)) {
								pRigidbody->m_force += Vector3(0, -50.f*dt, 0);
								//pos.y -= dt;
				}

				if (pInput->IsPressed(Key_SCANCODE_D)) {
								pRigidbody->m_force += Vector3(50.f*dt, 0, 0);
								//	pos.x += dt;
				}
				if (pInput->IsPressed(Key_SCANCODE_A)) {
								pRigidbody->m_force += Vector3(-50.f*dt, 0, 0);
								//pos.x -= dt;
				}
}

void PlayerController::Experience(float dt)
{
				expTimer += dt;
				if (expTimer >= 3.f) {

								experience += 5;
								expTimer = 0.f;

				}
}

