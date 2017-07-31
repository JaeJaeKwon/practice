#pragma once
#include "System.hpp"

#include <memory>

namespace SWE {
				class Physics : public System
				{
				public:
									//Magical singletern code
								  static Physics* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<Physics> instance(new Physics());
            return instance.get();
        }
								~Physics();

								//Initialize the system
								void Initialize(void) override;

							//All systems are updated every frame
								void Update(float dt) override;

				private:
								Physics();

				};

}