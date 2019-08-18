#include <iostream>
#include "Board.hpp"

void test(Board game)
{
    game.print();
    if (game.gameState() == X_WON)
        std::cout << "X won!\n" << std::endl;
    if (game.gameState() == O_WON)
        std::cout << "O won!\n" << std::endl;
}

int main()
{
    Board game;
    std::cout << "---Testing rows---\n" << std::endl;
    game.makeMove(1, 1, 'x');
    game.makeMove(1, 2, 'x');
    game.makeMove(1, 3, 'x');
    test(game);

    game.reset();
    game.makeMove(2, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(2, 3, 'x');
    test(game);

    game.reset();
    game.makeMove(3, 1, 'x');
    game.makeMove(3, 2, 'x');
    game.makeMove(3, 3, 'x');
    test(game);

    std::cout << "---Testing columns---\n" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'o');
    game.makeMove(2, 1, 'o');
    game.makeMove(3, 1, 'o');
    test(game);

    game.reset();
    game.makeMove(1, 2, 'o');
    game.makeMove(2, 2, 'o');
    game.makeMove(3, 2, 'o');
    test(game);

    game.reset();
    game.makeMove(1, 3, 'o');
    game.makeMove(2, 3, 'o');
    game.makeMove(3, 3, 'o');
    test(game);

    std::cout << "--Testing diagonals--" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(3, 3, 'x');
    test(game);

    game.reset();
    game.makeMove(1, 3, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(3, 1, 'x');
    test(game);

    return 0;
}
