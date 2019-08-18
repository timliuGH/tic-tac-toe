/*****************************************************************************
 * Class function implementation for Board
*****************************************************************************/
#include <iostream>
#include "Board.hpp"

/*****************************************************************************
 * Default constructor that starts with an empty board
*****************************************************************************/
Board::Board()
{
    reset();
}

/*****************************************************************************
 * This function takes the row and column in which to place either an x or o
 * and returns false if location is taken, true otherwise
 * @param row is row on 3x3 board 
 * @param col is column on 3x3 board
 * @param turn is either 'x' or 'o', depending on whose turn it is
 * @return false if location occupied, true otherwise and marks space
*****************************************************************************/
bool Board::makeMove(int row, int col, char turn)
{
    // Convert user's row and col input into indices of spaces array
    int rowIndex = row - 1;
    int colIndex = col - 1;

    // Check if location on board is taken
    if (spaces[rowIndex][colIndex] != 'o' && spaces[rowIndex][colIndex] != 'x')
    {
        spaces[rowIndex][colIndex] = turn;
        return true;
    }
    else
        return false;
}

/*****************************************************************************
 * Returns the State of the game (X_WON, O_WON, DRAW, UNFINISHED)
*****************************************************************************/
State Board::gameState()
{
    // Check if any rows, columns, or diagonals have same char
    if (_checkRows('x') || _checkColumns('x') || _checkDiagonals('x'))
        return X_WON;
    if (_checkRows('o') || _checkColumns('o') || _checkDiagonals('o'))
        return O_WON;
    return UNFINISHED;
}

/*****************************************************************************
 * Helper function for gameState; checks rows for winner
*****************************************************************************/
bool Board::_checkRows(char turn)
{
    if (( (spaces[0][0] == spaces[0][1]) && (spaces[0][1] == spaces[0][2]) 
                && toupper(spaces[0][0]) == toupper(turn)) ||
        ( (spaces[1][0] == spaces[1][1]) && (spaces[1][1] == spaces[1][2]) 
                && toupper(spaces[1][0]) == toupper(turn)) ||
        ( (spaces[2][0] == spaces[2][1]) && (spaces[2][1] == spaces[2][2]) 
                && toupper(spaces[2][0]) == toupper(turn))) 
        return true;
    else
        return false;
}

/*****************************************************************************
 * Helper function for gameState; checks columns for winner
*****************************************************************************/
bool Board::_checkColumns(char turn)
{
    if (( (spaces[0][0] == spaces[1][0]) && (spaces[1][0] == spaces[2][0]) 
                && toupper(spaces[0][0]) == toupper(turn)) ||
        ( (spaces[0][1] == spaces[1][1]) && (spaces[1][1] == spaces[2][1]) 
                && toupper(spaces[0][1]) == toupper(turn)) ||
        ( (spaces[0][2] == spaces[1][2]) && (spaces[1][2] == spaces[2][2]) 
                && toupper(spaces[0][2]) == toupper(turn))) 
        return true;
    else
        return false;
}

/*****************************************************************************
 * Helper function for gameState; checks columns for winner
*****************************************************************************/
bool Board::_checkDiagonals(char turn)
{
    if ( ( (spaces[0][0] == spaces[1][1]) && (spaces[1][1] == spaces[2][2])
            && tolower(spaces[0][0]) == turn ) ||
         ( (spaces[2][0] == spaces[1][1]) && (spaces[1][1] == spaces[2][0])
            && tolower(spaces[2][0]) == turn ))
        return true;
    else
        return false;
}

/*****************************************************************************
 * Output the board
*****************************************************************************/
void Board::print()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
            std::cout << spaces[row][col] << " ";
        std::cout << std::endl;
    }
}


/*****************************************************************************
 * Reset the board to empty spaces
*****************************************************************************/
void Board::reset()
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            spaces[row][col] = '_';
}
