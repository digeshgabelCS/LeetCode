#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;
                            if (solve(board))
                                return true;
                            board[row][col] = '.'; 
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false; 
            if (board[i][col] == c) return false; 
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false; 
        }
        return true;
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row)
            cout << c << ' ';
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Sudoku Puzzle:" << endl;
    printBoard(board);

    Solution solver;
    solver.solveSudoku(board);

    cout << "\nSolved Sudoku:" << endl;
    printBoard(board);

    return 0;
}