#pragma once
/*
Component.hpp
HeeJae Kwon
This class contains definition for the componet class, which 
gives identity to every Object in the game
*/
#include "ComponentType.hpp"

namespace SWE {

				//Forward declaration of Object class
				class Object;

				class Component
				{
				public:
								
								friend class Object;
								Component(ComponentType type) : Type(type) {}
								virtual ~Component() {};

								//Object will initialize all components
								virtual void Initialize() {}
								Object* GetOwner() { return pOwner; }
								void SetOwner(Object* owner) { pOwner = owner; }
								ComponentType GetType() {return Type;}

				private:
								Object* pOwner;
								ComponentType Type;
								//ComponentType pType;

				};
}
