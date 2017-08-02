#include "Sprite.hpp"
#include "Graphics.hpp"
#include "Transform.hpp"
#include "Object.hpp"

SWE::Sprite::Sprite() : Component(ComponentType::CT_SPRITE)
{
				Graphics::instance()->SpriteList.push_back(this);
}

SWE::Sprite::~Sprite()
{
			Graphics* graphic =	Graphics::instance();
			graphic->SpriteList.erase(std::find(graphic->SpriteList.begin(), 
																																							graphic->SpriteList.end(), this));
}

void SWE::Sprite::Initialize()
{
				pTransform = static_cast<Transform*>(GetOwner()->GetComponent(CT_TRANSFORM));
}
