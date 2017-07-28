#pragma once
#include "Component.hpp"
#include "ComponentType.hpp"
#include "vector3.hpp"

namespace SWE {

				class Transform : public Component
				{
				public:
								Transform() : Component(ComponentType::CT_TRANSFORM)
								{
												position.SetZero();
												rotation = 0;
								}

								Vector3 GetPosition() const { return position; }
								void SetPosition(const Vector3& pos) { position = pos; }
								float GetRotation() const { return rotation; }
								void SetRotation(float rot) { rotation = rot; }


				private:
								Vector3 position;
								float rotation;
				};

}