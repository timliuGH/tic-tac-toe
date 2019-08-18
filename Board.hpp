/******************************************************************************
 * Class specification for Board
******************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

enum State {X_WON, O_WON, DRAW, UNFINISHED};

const int rows = 3;
const int cols = 3;

class Board
{
    private:
        char spaces[rows][cols];
    public:
        Board();
        bool makeMove(int row, int col, char turn);
        State gameState();
        bool _checkRows(char turn);
        bool _checkColumns(char turn);
        bool _checkDiagonals(char turn);
        void print();
};

#endif
