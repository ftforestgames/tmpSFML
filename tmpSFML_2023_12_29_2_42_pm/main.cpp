#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "ResourceHolder.h"

using namespace sf;
using namespace std;

int main(int argc, char* argv[])
{
    Game game;
    game.run();

    return 0;
}
