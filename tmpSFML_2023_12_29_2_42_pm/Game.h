#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

class Game
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
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
	float PlayerSpeed = 100.f;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	int mStatisticsNumFrames;
};
