#include <iostream>
#include "Board.hpp"

int main()
{
    Board game;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << game.spaces[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
