#pragma once
#include "libs.h"

#include "World.h"

using namespace sf;
using namespace std;

class Game : private sf::NonCopyable
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key,
		bool isPressed);
	void updateStatistics(sf::Time elapsedTime);
	template <typename T>
	std::string toString(const T& value);
private:
	
	
	//sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	

	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	World					mWorld;

	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
};
