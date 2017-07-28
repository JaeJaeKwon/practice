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
				transform = static_cast<Transform*>(GetOwner()->GetComponent(CT_TRANSFORM));
}

void PlayerController::Update(float dt)
{
				Movement();
				Experience(dt);
				if (Input::IsTriggered(SDL_SCANCODE_F)) {
								--health;
				}
					transform->SetPosition(pos);

					std::cout << transform->GetPosition().x << " " <<
									transform->GetPosition().y << " " <<
									transform->GetPosition().z << "\n";
																		
}

void SWE::PlayerController::Movement()
{
			if (Input::IsPressed(SDL_SCANCODE_W)) {
								++pos.y;
				}
				if (Input::IsPressed(SDL_SCANCODE_S)) {
								--pos.y;
				}

if (Input::IsPressed(SDL_SCANCODE_D)) {
								++pos.x;
				}
				if (Input::IsPressed(SDL_SCANCODE_A)) {
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

