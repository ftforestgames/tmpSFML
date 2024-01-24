#pragma once
#include "libs.h"

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Aircraft.h"
#include "Ground.h"
#include "CommandQueue.h"


#include <array>

class World : private sf::NonCopyable
{
	public:
		explicit		World(sf::RenderWindow& window);
		void			update(sf::Time dt);
		void			draw();

		CommandQueue&	getCommandQueue();
	private:
		void loadTextures();
		void buildScene();
		void								adaptPlayerPosition();
		void								adaptPlayerVelocity();

	private:
		enum Layer
		{
			Background,
			GroundEnemy,
			Air,
			LayerCount
		};
	private:
		sf::RenderWindow& mWindow;
		sf::View mWorldView;
		TextureHolder mTextures;

		SceneNode mSceneGraph;
		std::array<SceneNode*, LayerCount> mSceneLayers;
		CommandQueue						mCommandQueue;

		sf::FloatRect mWorldBounds;
		sf::Vector2f mSpawnPosition;
		float mScrollSpeed;
		Aircraft* mPlayerAircraft;
		
		Ground* mEnemy;
};

