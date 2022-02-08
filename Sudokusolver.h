#pragma once
class Sudokusolver
{
private:
public:
    static void Print(int board[9][9]);
    static bool checkLine(int board[9][9], int n, int row, int col);
    static bool checkBox(int board[9][9], int n, int row, int col);
    static bool isValid(int board[9][9], int n, int row, int col);
    static bool solveBoard(int board[9][9]);
};

