#pragma once
#include "System.hpp"

#include <memory>
#include <vector>

namespace SWE {
				class Rigidbody;
				class Pair
				{
				public:
								Pair(Rigidbody* lhs, Rigidbody* rhs) : m_lhs(lhs),m_rhs(rhs) {}

												Rigidbody* m_lhs,* m_rhs;
				private:

				};

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
								//void Initialize(void) override;

							//All systems are updated every frame
								void Update(float dt) override;


								//vector of pointer to Rigidbody
								std::vector<Rigidbody*> RigidbodyList;
				private:
								Physics();

								//Explicit Euler (Forward Euler) Integrator
								void ExplicitEulerIntegrator(float dt);
								void BroadPhase();
								bool AABBAABBCollisionCheck(Rigidbody*lhs, Rigidbody* rhs);
								std::vector<Pair> m_vecpair;

				};

}