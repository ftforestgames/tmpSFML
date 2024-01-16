#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "ResourceHolder.h"

using namespace sf;
using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        Game game;
        game.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
