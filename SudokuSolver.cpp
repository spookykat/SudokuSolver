#include "Sudokusolver.h"
#include <iostream>


void Sudokusolver::Print(int board[9][9]){
    for (int rows = 0; rows < (sizeof(board[0])/sizeof(*board[0])); rows++)
    {
        for (int cols = 0; cols < (sizeof(board[0])/sizeof(*board[0])); cols++)
        {
            std::cout << board[rows][cols] << " ";
            if((cols + 1) % 3 == 0 && cols != 8){
                std::cout << "|";
            }
        }
        if((rows + 1) % 3 == 0 && rows != 8){
            std::cout << "\n-------------------";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
bool Sudokusolver::checkLine(int board[9][9], int n, int row, int col){
    for (int number = 0; number < (sizeof(board[0])/sizeof(*board[0])); number++)
    {
        if (board[row][number] == n || board[number][col] == n)
        {
            return false;
        }
    }
    return true;
}
bool Sudokusolver::checkBox(int board[9][9], int n, int row, int col){
    int topRow, topCol;
    topRow = row / 3 * 3;
    topCol = col / 3 * 3;
    for (int i = topRow; i < topRow + 3; i++)
    {
        for (int j = topCol; j < topCol + 3; j++)
        {
            if (board[i][j] == n)
            {
                return false;
            } 
        }   
    }
    return true;
}
bool Sudokusolver::isValid(int board[9][9], int n, int row, int col){
    return checkLine(board, n, row, col) && checkBox(board, n, row, col);
}
bool Sudokusolver::solveBoard(int board[9][9]){
    for (int rows = 0; rows < (sizeof(board[0])/sizeof(*board[0])); rows++)
    {
        for (int cols = 0; cols < (sizeof(board[0])/sizeof(*board[0])); cols++)
        {
            if (board[rows][cols] == 0)
            {
                for (int nToTry = 0; nToTry <= (sizeof(board[0])/sizeof(*board[0])); nToTry++)
                {
                    if (isValid(board,nToTry, rows, cols))
                    {
                        board[rows][cols] = nToTry;
                        if (solveBoard(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[rows][cols] = 0;
                        }
                    }
                    
                }
                return false;
            }
        }
    }
    Print(board);
    return true;
}