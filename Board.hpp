/******************************************************************************
 * Class specification for Board
******************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

const int rows = 3;
const int cols = 3;

class Board
{
    public:
        char spaces[rows][cols];
    public:
        Board();
        bool makeMove(int row, int col, char turn);
};

#endif
