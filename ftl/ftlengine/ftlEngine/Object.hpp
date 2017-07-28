#pragma once
/*
Object.hpp
HeeJae Kwon

Contains definition for the Object class which each and every
entities in the game engine will be built upon.
*/

#include "Component.hpp"
#include "Transform.hpp"
#include "ComponentType.hpp"
#include "Controller.hpp"
#include <vector>
#include <memory>

namespace SWE {

				typedef unsigned int ObjectID;
				class Object
				{
				public:
								//Todo: friend class to ObjectFactory

								Object();
								~Object();

								void Initialize();
								//Properly destroy the object by delay destruction
								void Destroy();
								bool AddComponent(Component* pComponent);
								Component* GetComponent(ComponentType type);

				private:
								std::vector<std::unique_ptr<Component>> pCompVec;
								ObjectID objID;
								/*All different types of pointers to different components
								but set to nullptyr if component doesn't exist
								*/


								Transform* transform;
								Controller* controller;
	//							Sprite* sprite
		//						Body* body
			//					Logic* logic
								

				};

}
