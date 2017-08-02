/*
Obejct.cpp
HeeJae Kwon
*/
#include "Object.hpp"
#include "Sprite.hpp"
#include "Rigidbody.hpp"
#include "Transform.hpp"
#include "Controller.hpp"
#include "Sprite.hpp"

using namespace SWE;

Object::Object() : transform(nullptr), controller(nullptr), sprite(nullptr)
{
}

Object::~Object()
{
				if (transform) {
							delete	transform;
							transform = nullptr;
				}
				if (controller) {
								delete controller;
								controller = nullptr;
				}
				if (sprite) {
								delete sprite;
								sprite = nullptr;
				}
				if (rigidbody) {
								delete rigidbody;
								rigidbody = nullptr;
				}
				

//				Destroy();
}

void Object::Initialize()
{
				//pCompVec
				if (transform) {
								transform->Initialize();
				}
				if (controller) {
								controller->Initialize();
				}
				if (sprite) {
								sprite->Initialize();
				}
				if (rigidbody) {
								rigidbody->Initialize();
				}
}

//Signal the object 
//void Object::Destroy()
//{
//}

bool Object::AddComponent(Component* pComponent)
{
				//Add component and return true if success
				ComponentType type= pComponent->GetType();
				if (type > CT_INVALID && type < CT_NUM_COMPONENTS) {
								pComponent->SetOwner(this);
				}
				switch (type)
				{
				case CT_TRANSFORM: { transform = static_cast<Transform*>(pComponent); return true; }break;
				case CT_CONTROLLER: { controller = static_cast<Controller*>(pComponent); return true; }break;
				case CT_SPRITE: { sprite = static_cast<Sprite*>(pComponent); return true; }break;
				case CT_RIGIDBODY: { rigidbody = static_cast<Rigidbody*>(pComponent); return true; }break;
				default:
								break;
				}
				return false; //if failed
}

Component* Object::GetComponent(ComponentType type)
{
				switch (type)
				{
				case CT_TRANSFORM: {
								return transform;
				}break;
				case CT_CONTROLLER: {
								return controller;
				}break;	
				case CT_SPRITE: {
								return sprite;
				}break;
				case CT_RIGIDBODY: {
								return rigidbody;
				}break;
				}

				return nullptr;
}

