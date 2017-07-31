#pragma once
#include "Component.hpp"

namespace SWE {
				class Sprite : public Component
				{
				public:
								Sprite() : Component(ComponentType::CT_SPRITE) {}
								~Sprite();

				private:

				};
}