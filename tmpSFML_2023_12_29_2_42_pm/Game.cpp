#include "Game.h"
#include "ResourceHolder.h"

using namespace sf;
using namespace std;

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mTexture()
	, mPlayer()
	, airplane()
	, landscape()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
{
	// Try to load resources
	

	//sf::Image heroimage; //создаем объект Image (изображение)
	//heroimage.loadFromFile("images/eagle.png");//загружаем в него файл

	//mTexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)
	//
	//mPlayer.setTexture(mTexture);
	//mPlayer.setPosition(100.f, 100.f);

	mFont.loadFromFile("media/sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
	mStatisticsText.setFillColor(Color::Green);
}
template <typename T>
std::string Game::toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	ResourceHolder<sf::Texture, Textures::ID> textures;
	try
	{
		textures.load(Textures::Landscape, "images/desert.png");
		textures.load(Textures::Airplane, "images/eagle.png");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return;
	}

	// Access resources
	airplane.setTexture(textures.get(Textures::Airplane));
	landscape.setTexture(textures.get(Textures::Landscape));
	airplane.setPosition(200.f, 200.f);

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		updateStatistics(TimePerFrame);
		render();
	}
}
void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;
	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::render()
{
	mWindow.clear();
	//mWindow.draw(mPlayer);
	mWindow.draw(landscape);
	mWindow.draw(airplane);
	mWindow.draw(mStatisticsText);
	mWindow.display();
}
void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}