#define M_PI 3.14159265358979323846
#include "ActionTarget.h"

#pragma once

class Player : public sf::Drawable, public ActionTarget {
	public:
		Player(const Player&) = delete;
		Player& operator=(const Player&) = delete;
		Player() : _shape(sf::Vector2f(32, 32))
			, _isMoving(false),
			_rotation(0)
		{
			_shape.setFillColor(sf::Color::Blue);
			_shape.setOrigin(16, 16);

			bind(Action(sf::Keyboard::Up,Action::Type::Pressed), [this](const sf::Event&){_isMoving = true;});
			bind(Action(sf::Keyboard::Left, Action::Type::Pressed), [this](const sf::Event&){_rotation -= 1;});
			bind(Action(sf::Keyboard::Right, Action::Type::Pressed), [this](const sf::Event&){_rotation += 1;});
		}
		template<typename ... Args>
		void setPosition(Args&& ... args) {
			_shape.setPosition(std::forward<Args>(args)...);
		}
		
		void processEvents()
		{
			_isMoving = false;
			_rotation = 0;
			ActionTarget::processEvents();
		}
		void update(sf::Time deltaTime)
		{
			float seconds = deltaTime.asSeconds();
			if (_rotation != 0)
			{
				float angle = (_rotation > 0 ? 1 : -1) * 180 * seconds;
				_shape.rotate(angle);
			}
			if (_isMoving)
			{
				float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
				_velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) *
					60.f * seconds;
			}
			_shape.move(seconds * _velocity);
		}
		bool _isMoving;
		int _rotation;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(_shape, states);
		}
		sf::RectangleShape _shape;
		sf::Vector2f _velocity;
};

