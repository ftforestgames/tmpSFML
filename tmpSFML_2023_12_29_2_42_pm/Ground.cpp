#include "Ground.h"

Textures::ID toTextureID(Ground::Type type)
{
	switch (type)
	{
		case Ground::Submarine:
			return Textures::Submarine;

		return Textures::Submarine;
	}
}
	Ground::Ground(Type type, const TextureHolder& textures)
	: mType(type)
	, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Ground::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}