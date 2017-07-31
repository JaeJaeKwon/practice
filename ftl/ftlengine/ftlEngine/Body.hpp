#pragma once
#include "Component.hpp"

namespace SWE {
				class Body : public Component
				{
				public:
								Body() : Component(ComponentType::CT_BODY) {}
								~Body();

				private:

				};
}