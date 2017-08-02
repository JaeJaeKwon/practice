#pragma once
#include "Component.hpp"
#include "Graphics.hpp"
#include "vector3.hpp"

namespace SWE {
				class Transform;
				class Sprite : public Component
				{
				public:
								Sprite();
								~Sprite();

								void Initialize() override;


								Vector3 Size;
								float color[4];
								unsigned int TextureID;

								Transform* pTransform;

				private:

				};
}