#include "Physics.hpp"
#include "Rigidbody.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "Object.hpp"
#include "Application.hpp"

#include <iostream>
using namespace SWE;

Physics::Physics()
{
}

Physics::~Physics()
{
}

//void Physics::Initialize(void)
//{
//}

void Physics::Update(float dt)
{
				ExplicitEulerIntegrator(dt);
				BroadPhase();
}

void Physics::ExplicitEulerIntegrator(float dt)
{
				Transform* pTr = nullptr;
				Vector3 curfp;
				for (auto & rigidbody : RigidbodyList) {
								//Explici Euler method
								//f(t + dt) = f(t) + f'(t)dt
								//Next frame's position = current frame's position + (vector*dt)
								pTr = rigidbody->m_pTransform;

						//p' = p + vt
						curfp = pTr->GetPosition();
						pTr->SetPosition(curfp + (rigidbody)->pm_velocity*dt);
						//v' = v +at = v + (F/m*t)
						rigidbody->pm_velocity = rigidbody->pm_velocity + 
																														(rigidbody->m_force *rigidbody->pm_invmass)*dt;
						
						rigidbody->m_force.SetZero();

				}
}

void Physics::BroadPhase()
{
				for (auto it = RigidbodyList.begin(); it != RigidbodyList.end(); ++it) {
								for (auto jt = it + 1; jt != RigidbodyList.end(); ++jt) {
												//Check collision between two AABB objects,
												//put the pair into the container.
												if (AABBAABBCollisionCheck(*it,*jt)) {
																m_vecpair.emplace_back(*it, *jt);
												}

								}
				}

}

bool Physics::AABBAABBCollisionCheck(Rigidbody * pA, Rigidbody * pB)
{
				Sprite* SpriteA = static_cast<Sprite*>(pA->GetOwner()->GetComponent(CT_SPRITE));
				Sprite* SpriteB = static_cast<Sprite*>(pB->GetOwner()->GetComponent(CT_SPRITE));
				Vector3 asize = Vector3(SpriteA->Size), apos = Vector3(pA->m_pTransform->GetPosition().x * 
																																																											Application::instance()->screenWidth /2,
																																																											pA->m_pTransform->GetPosition().y * 
																																																											Application::instance()->screenHeight /2, 0);
				Vector3 bsize = Vector3(SpriteB->Size),	bpos = Vector3(pB->m_pTransform->GetPosition().x * 
																																																											Application::instance()->screenWidth /2,
																																																											pB->m_pTransform->GetPosition().y * 
																																																											Application::instance()->screenHeight /2, 0);


				Vector3 atl, abr;
				Vector3 btl, bbr;

				atl = Vector3(apos.x-asize.x/2.f, apos.y+asize.y/2.f,0);
				abr = Vector3(apos.x+asize.x/2.f, apos.y-asize.y/2.f,0);
				btl = Vector3(bpos.x-bsize.x/2.f, bpos.y+bsize.y/2.f,0);
				bbr = Vector3(bpos.x+bsize.x/2.f, bpos.y-bsize.y/2.f,0);

				if (atl.x > bbr.x) {
				std::cout << "FALSE\n";
							return false;
				}

				if (btl.x >abr.x) {
				std::cout << "FALSE\n";
								return false;
				}

				if (abr.y>btl.y) {
				std::cout << "FALSE\n";
								return false;
				}
				if (bbr.y>atl.y) {
				std::cout << "FALSE\n";
								return false;
				}
				std::cout << "TRUE\n";
				return true;
}

