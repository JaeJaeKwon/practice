#pragma once
#include "Component.hpp"
#include "vector3.hpp"

namespace SWE {
				class Transform;
				class Rigidbody : public Component
				{
				public:
								Rigidbody(const Vector3& rhs, float inv_mass);
								~Rigidbody();

								void Initialize() override;

								Vector3 m_force;
								Transform* m_pTransform;


				private:
								friend class Physics;

								Rigidbody();
								float pm_invmass;
								Vector3 pm_velocity;

				};
}