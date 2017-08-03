#pragma once
/*
Factory.hpp
HeeJae Kwon
*/

#include "System.hpp"
#include "Object.hpp"

#include <map>
#include <memory>
				class Vector3;
namespace SWE {
				class ObjectFactory : public System
				{
				public:
															//Magical singletern code
								  static ObjectFactory* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<ObjectFactory> instance(new ObjectFactory());
            return instance.get();
        }
								~ObjectFactory();

								//void Initialize() override;
								void Update(float dt) override;

								//Add an object to the destroy list for delay destruction
								void Destroy(Object*);

								//For the shutdown of the Factory
								void DestroyAllObjects();

								//ID the object and store it in the object list(map)
								void IDGameObject(Object* gameObject);

								//Return an object with specific ID
								Object* GetObjectwID(ObjectID id);

								Object* CreateEmptyObject();
								//Showing how to create an object through hardcode
								//Todo: When applying data driven methods, use this as blueprint
								Object * CreatePlayer(const Vector3 & position, const Vector3 & velocity, float mass);
								Object * CreateAsteroid(const Vector3 & position, const Vector3 & velocity, float mass);
								

				private:
								ObjectFactory();
								//Used to incrementally generate unique Ids
								ObjectID LastObjectID;

								//Map of Objects to their IDs used ofr safe referencing
								std::map<ObjectID, Object*> ObjectIDMap;

								//List of Objects to be deleted
								//To prevent problems of early or multi call of Object's destruction
								std::vector<Object*> ObjectsToBeDeleted;

				};

}