#pragma once
#include "Player.h"

class Game
{
	public:
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		Game() : _window(sf::VideoMode(800, 600), "02_Game_Archi"),
			_player()
		{
			
		};
		void run(int minimum_frame_per_seconds)
		{
			sf::Clock clock;
			sf::Time timeSinceLastUpdate;
			sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);
			while (_window.isOpen()) {
				processEvents();
				timeSinceLastUpdate = clock.restart();
				while (timeSinceLastUpdate > TimePerFrame) {
					timeSinceLastUpdate -= TimePerFrame;
					update(TimePerFrame);
				}
				update(timeSinceLastUpdate);
				render();
			}
		}
	private:
		void processEvents()
		{
			sf::Event event;
			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window.close();
				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
						_window.close();
					else if (event.key.code == sf::Keyboard::Up)
						_player._isMoving = true;
					else if (event.key.code == sf::Keyboard::Left)
						_player._rotation = -1;
					else if (event.key.code == sf::Keyboard::Right)
						_player._rotation = 1;
				}
				else if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
						_player._isMoving = false;
					else if (event.key.code == sf::Keyboard::Left)
						_player._rotation = 0;
					else if (event.key.code == sf::Keyboard::Right)
						_player._rotation = 0;
				}
			}
		}
		void update(sf::Time deltaTime)
		{
			_player.update(deltaTime);
		}
		void render()
		{
			_window.clear();
			_window.draw(_player);
			_window.display();
		}
		sf::RenderWindow _window;
		Player _player;

		
};

