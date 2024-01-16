#pragma once
#include "libs.h"
#include "SceneNode.h"
class Entity : public SceneNode
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	sf::Vector2f mVelocity;
	virtual void updateCurrent(sf::Time dt);
};