#pragma once
#include "libs.h"

class SceneNode :
	public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef unique_ptr<SceneNode> Ptr;
public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	void update(sf::Time dt);
	sf::Vector2f			getWorldPosition() const;
	sf::Transform			getWorldTransform() const;
private:
	virtual void draw(sf::RenderTarget& target,
		sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget & target,
		sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};