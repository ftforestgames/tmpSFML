#pragma once
#include "libs.h"
#include "Player.h"


#include "World.h"

using namespace sf;
using namespace std;

class Game : private sf::NonCopyable
{
public:
	Game();
	void run();
private:
	void	processEvents();
	void render();
	void processInput();
	void updateStatistics(sf::Time elapsedTime);
	void update(sf::Time elapsedTime);
	template <typename T>
	std::string toString(const T& value);
private:
	
	
	//sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	

	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	World					mWorld;
	Player					mPlayer;

	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;

	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingLeft;
	bool					mIsMovingRight;
};
