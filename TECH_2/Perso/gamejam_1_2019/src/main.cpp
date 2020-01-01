#include <iostream>
#include "Game.hpp"
#include "Definition.hpp"

int main ()
{
    srand(time(NULL));
    Gengine::Game(WIDTH, HEIGHT, "Bailiff shall not pass !");

    return (EXIT_SUCCESS);
}
