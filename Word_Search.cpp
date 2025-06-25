#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        function<bool(int, int, int)> dfs = [&](int row, int col, int index) {
            if (index == word.size()) return true;

            if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index])
                return false;

            char temp = board[row][col];
            board[row][col] = '#';

            bool found = dfs(row - 1, col, index + 1) ||
                         dfs(row + 1, col, index + 1) ||
                         dfs(row, col - 1, index + 1) ||
                         dfs(row, col + 1, index + 1);

            board[row][col] = temp;

            return found;
        };

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Word '" << word1 << "' exists: " << (solution.exist(board, word1) ? "true" : "false") << endl;
    cout << "Word '" << word2 << "' exists: " << (solution.exist(board, word2) ? "true" : "false") << endl;
    cout << "Word '" << word3 << "' exists: " << (solution.exist(board, word3) ? "true" : "false") << endl;

    return 0;
}
