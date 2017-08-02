#include "Factory.hpp"
#include "..\..\examples\ftlgame\PlayerController.hpp"
#include "Transform.hpp"
#include "Graphics.hpp"
#include "Rigidbody.hpp"
#include "Sprite.hpp"
#include "DebugUtil.hpp"

using namespace SWE;

ObjectFactory::ObjectFactory() : LastObjectID(0)
{
}

ObjectFactory::~ObjectFactory()
{
				DestroyAllObjects();
}

void ObjectFactory::Initialize()
{
}

void ObjectFactory::Update(float /*dt*/)
{
				//Todo: Delete all object in the ObjectToBeDeleted list
				for( auto it = ObjectsToBeDeleted.begin(); it  != ObjectsToBeDeleted.end(); ++it) {
				
								Object* gameObject = *it;
								auto IDit = ObjectIDMap.find(gameObject->objID);
								DEBUG_ASSERT(IDit == ObjectIDMap.end(), "Object is bad memory.");
								if (IDit != ObjectIDMap.end()) {
												//delete and remove from the map
												delete gameObject;
												ObjectIDMap.erase(IDit);
								}
				}
				ObjectsToBeDeleted.clear();
}

void ObjectFactory::Destroy(Object* gameObject_)
{
				ObjectsToBeDeleted.push_back(gameObject_);
}

void ObjectFactory::DestroyAllObjects()
{
				for (auto & it : ObjectIDMap)
				{
								delete it.second;
				}
				ObjectIDMap.clear();
}


void ObjectFactory::IDGameObject(Object* gameObject_)
{
		//Just increment the-LastObjectID used. Does not handle overflow
				//but it would take oer 4 billion objects to break
				++LastObjectID;
				gameObject_->objID = LastObjectID;

				//Store the game object in the ObjectIDMap
				ObjectIDMap[LastObjectID] = gameObject_;

}

Object * ObjectFactory::GetObjectwID(ObjectID id)
{
			auto it = 	ObjectIDMap.find(id);
			if (it != ObjectIDMap.end()) {
							return it->second;
			}
			return nullptr;
}

Object * ObjectFactory::CreateEmptyObject()
{
				Object* gameObject = new Object();
				IDGameObject(gameObject);
				return gameObject;
}

Object * ObjectFactory::CreatePlayer(const Vector3& position, const Vector3& velocity, float mass)
{
				Object* player = CreateEmptyObject();
				Transform* transform = new Transform();
				transform->SetPosition(position);
				player->AddComponent(transform);

				//Todo: add Sprite and Body components
				Sprite* sprite = new Sprite();
				sprite->Size.Set(100, 100, 0);
				sprite->TextureID = 1;

				player->AddComponent(sprite);
				player->AddComponent(new Rigidbody(velocity, mass));
				player->AddComponent(new PlayerController());
				player->Initialize();

				return player;
}
