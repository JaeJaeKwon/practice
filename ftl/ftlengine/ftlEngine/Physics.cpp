#include "Physics.hpp"
#include "Rigidbody.hpp"
#include "Transform.hpp"
#include "Object.hpp"
using namespace SWE;

Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::Initialize(void)
{
}

void Physics::Update(float dt)
{
				ExplicitEulerIntegrator(dt);
}

void Physics::ExplicitEulerIntegrator(float dt)
{
				Transform* pTr = nullptr;
				Vector3 curfp;
				for (auto & rigidbody : RigidbodyList) {
								//Explici Euler method
								//f(t + dt) = f(t) + f'(t)dt
								//Next frame's position = current frame's position + (vector*dt)
						pTr = 	static_cast<Transform*>(rigidbody->GetOwner()->GetComponent(CT_TRANSFORM));

						//p' = p + vt
						curfp = pTr->GetPosition();
						pTr->SetPosition(curfp + (rigidbody)->pm_velocity*dt);
						//v' = v +at = v + (F/m*t)
						rigidbody->pm_velocity = rigidbody->pm_velocity + 
																														(rigidbody->m_force *rigidbody->pm_invmass)*dt;
						
						rigidbody->m_force.SetZero();

				}
}

