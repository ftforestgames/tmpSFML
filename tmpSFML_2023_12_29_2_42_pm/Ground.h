#pragma once

#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

class Ground : public Entity
{
public:
	enum Type
	{
		Submarine,
	};
public:
	Ground(Type type, const TextureHolder& textures);


private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	Type		mType;
	sf::Sprite	mSprite;
};


