/******************************************************************************
 * Class function implementation for Board
******************************************************************************/
#include "Board.hpp"

/******************************************************************************
 * Default constructor that starts with an empty board
******************************************************************************/
Board::Board()
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            spaces[row][col] = ' ';
}

/******************************************************************************
 * This function takes the row and column in which to place either an x or o
 * and returns false if location is taken, true otherwise
 * @param row is row on 3x3 board 
 * @param col is column on 3x3 board
 * @param turn is either 'x' or 'o', depending on whose turn it is
 * @return false if location occupied, true otherwise
******************************************************************************/
bool makeMove(int row, int col, char turn)
{
    // Convert user's row and col input into indices of spaces array
    int rowIndex = row - 1;
    int colIndex = col - 1;

    // Check if location on board is taken
    if (spaces[rowIndex][colIndex] == ' ')
    {
        spaces[rowIndex][colIndex] = turn;
        return true;
    }

    return false;
}
