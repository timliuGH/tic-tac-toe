#include <iostream>
#include "Board.hpp"

int test(Board game)
{
    game.print();
    if (game.gameState() == X_WON)
    {
        std::cout << "X won!\n" << std::endl;
        return X_WON;
    }
    if (game.gameState() == O_WON)
    {
        std::cout << "O won!\n" << std::endl;
        return O_WON;
    }
    if (game.gameState() == UNFINISHED)
    {
        std::cout << "Game is unfinished\n" << std::endl;
        return UNFINISHED;
    }
    if (game.gameState() == DRAW)
    {
        std::cout << "Cat's cradle!\n" << std::endl;
        return DRAW;
    }
    else
    {
        std::cout << "not a State\n" << std::endl;
        return -1;
    }
}

int main()
{
    Board game;
    std::cout << "---Testing rows---\n" << std::endl;
    game.makeMove(1, 1, 'x');
    game.makeMove(1, 2, 'x');
    game.makeMove(1, 3, 'x');
    if (test(game) != X_WON) 
        return -1;

    game.reset();
    game.makeMove(2, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(2, 3, 'x');
    if (test(game) != X_WON)
        return -1;

    game.reset();
    game.makeMove(3, 1, 'x');
    game.makeMove(3, 2, 'x');
    game.makeMove(3, 3, 'x');
    if (test(game) != X_WON)
        return -1;

    std::cout << "---Testing columns---\n" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'o');
    game.makeMove(2, 1, 'o');
    game.makeMove(3, 1, 'o');
    if (test(game) != O_WON)
        return -1;

    game.reset();
    game.makeMove(1, 2, 'o');
    game.makeMove(2, 2, 'o');
    game.makeMove(3, 2, 'o');
    if (test(game) != O_WON)
        return -1;

    game.reset();
    game.makeMove(1, 3, 'o');
    game.makeMove(2, 3, 'o');
    game.makeMove(3, 3, 'o');
    if (test(game) != O_WON)
        return -1;

    std::cout << "--Testing diagonals--" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(3, 3, 'x');
    if (test(game) != X_WON)
        return -1;

    game.reset();
    game.makeMove(1, 3, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(3, 1, 'x');
    if (test(game) != X_WON)
        return -1;

    std::cout << "--Testing UNFINISHED--" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'o');
    game.makeMove(1, 2, 'o');
    game.makeMove(1, 3, 'x');
    game.makeMove(2, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(2, 3 ,'o');
    game.makeMove(3, 1, 'o');
    game.makeMove(3, 2, 'x');
    //game.makeMove(3, 3, 'x');
    if (test(game) != UNFINISHED)
        return -1;

    std::cout << "--Testing WINNER && UNFINISHED--" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'o');
    game.makeMove(1, 2, 'o');
    game.makeMove(1, 3, 'x');
    game.makeMove(2, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(2, 3 ,'x');
    game.makeMove(3, 1, 'o');
    //game.makeMove(3, 3, 'x');
    if (test(game) != X_WON)
        return -1;

    std::cout << "--Testing DRAW--" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'o');
    game.makeMove(1, 2, 'o');
    game.makeMove(1, 3, 'x');
    game.makeMove(2, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(2, 3 ,'o');
    game.makeMove(3, 1, 'o');
    game.makeMove(3, 2, 'x');
    game.makeMove(3, 3, 'x');
    if (test(game) != DRAW)
        return -1;

    std::cout << "--Testing WINNER && DRAW--" << std::endl;
    game.reset();
    game.makeMove(1, 1, 'o');
    game.makeMove(1, 2, 'o');
    game.makeMove(1, 3, 'x');
    game.makeMove(2, 1, 'x');
    game.makeMove(2, 2, 'x');
    game.makeMove(2, 3 ,'x');
    game.makeMove(3, 1, 'o');
    game.makeMove(3, 2, 'x');
    game.makeMove(3, 3, 'o');
    if (test(game) != X_WON)
        return -1;

    std::cout << "All tests passed." << std::endl;

    return 0;
}
