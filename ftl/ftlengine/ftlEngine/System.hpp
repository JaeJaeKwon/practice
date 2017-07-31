#pragma once
/*
Systems.hpp
HeeJae Kwon
A pure virtual base class (an interface) that is the base class for all
systems used by the Engine
*/

namespace SWE {

				class System
				{
				public:
								//Initialize the system
								virtual void Initialize(void) {};

							//All systems are updated every frame
								virtual void Update(float dt) = 0;

								//All systems need a virtual destructor to their desturctors called
								virtual ~System() {};

				private:

				protected:
				};

} //namespace SWE end


//
//
//
//
//
//
//
