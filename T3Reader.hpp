/******************************************************************************
 * Class specification for T3Reader
 * Reads a file of Tic Tac Toe moves
******************************************************************************/
#ifndef T3READER_HPP
#define T3READER_HPP

#include <string>
#include "Board.hpp"

class T3Reader
{
    private:
        Board board;
        char turn;
    public:
        T3Reader(char firstPlayer) { turn = firstPlayer; }
        bool readGameFile(std::string file);
};

#endif
