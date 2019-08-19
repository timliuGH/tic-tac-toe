/******************************************************************************
 * Class function implementation file for T3Reader
 * Reads a file of Tic Tac Toe moves
******************************************************************************/
#include <fstream>
#include "T3Reader.hpp"

/******************************************************************************
 * Reads the game file and returns false if move occupied, true otherwise
******************************************************************************/
bool T3Reader::readGameFile(std::string file)
{
    std::ifstream inputFile(file.c_str());
    int row;
    int col;
    while (inputFile >> row >> col)
    {
        if (board.makeMove(row, col, turn))
        {
            if (tolower(turn) == 'o')
                turn = 'x';
            else
                turn = 'o';
        }
        else
        {
            inputFile.close();
            return false;
        }
    }

    inputFile.close();
    board.print();
    return true;
}
