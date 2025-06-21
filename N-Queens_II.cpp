#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);               // columns under attack
        vector<bool> diag1(2 * n - 1, false);      // major diagonals under attack
        vector<bool> diag2(2 * n - 1, false);      // minor diagonals under attack
        solve(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void solve(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
                continue;

            // place queen
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            // move to next row
            solve(row + 1, n, cols, diag1, diag2, count);

            // backtrack
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n for N-Queens: ";
    cin >> n;

    int totalSolutions = solution.totalNQueens(n);
    cout << "Total distinct solutions for " << n << "-Queens: " << totalSolutions << endl;

    return 0;
}