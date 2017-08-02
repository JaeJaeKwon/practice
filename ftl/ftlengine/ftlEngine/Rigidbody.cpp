#include "Rigidbody.hpp"
#include "Physics.hpp"

using namespace SWE;
Rigidbody::Rigidbody(const Vector3 & vel, float inv_mass) : Component(ComponentType::CT_RIGIDBODY),
pm_velocity(vel), pm_invmass(inv_mass)
{
				//Put the pointer to component to the vector container,
				//so that Physics system can iterate through.
				Physics::instance()->RigidbodyList.push_back(this);
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Initialize()
{
}
