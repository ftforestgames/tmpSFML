#include <SFML/Graphics.hpp>

#include "Game.h"

using namespace sf;


int main(int argc, char* argv[])
{
    Game game;
    game.run(1);

    /*RenderWindow window(VideoMode(400, 400), L"����� ������", Style::Default);

    window.setVerticalSyncEnabled(true);

    CircleShape shape(100.f, 3);
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Blue);
        window.draw(shape);
        window.display();
    }*/
    return 0;
}