#include "PlayerController.hpp"
#include "Input.hpp"				
#include "Object.hpp"
#include "Transform.hpp"

using namespace SWE;

PlayerController::PlayerController()
{
				health = 20;
				experience = 0;
				expTimer = 3.f;
				pos.SetZero();
}

PlayerController::~PlayerController()
{
}

void PlayerController::Initialize()
{
				pTransform = static_cast<Transform*>(GetOwner()->GetComponent(CT_TRANSFORM));
}

void PlayerController::Update(float dt)
{
				Movement();
				Experience(dt);
				if (Input::instance()->IsTriggered(SDL_SCANCODE_F)) {
								--health;
				}
					pTransform->SetPosition(pos);

					std::cout << pTransform->GetPosition().x << " " <<
									pTransform->GetPosition().y << " " <<
									pTransform->GetPosition().z << "\n";
																		
}

void SWE::PlayerController::Movement()
{
				Input* pInput = Input::instance();
			if (pInput->IsPressed(SDL_SCANCODE_W)) {
								++pos.y;
				}
				if (pInput->IsPressed(SDL_SCANCODE_S)) {
								--pos.y;
				}

if (pInput->IsPressed(SDL_SCANCODE_D)) {
								++pos.x;
				}
				if (pInput->IsPressed(SDL_SCANCODE_A)) {
								--pos.x;
				}

}

void SWE::PlayerController::Experience(float dt)
{
				expTimer += dt;
				if (expTimer >= 3.f) {

								experience += 5;
								expTimer = 0.f;

				}
}

