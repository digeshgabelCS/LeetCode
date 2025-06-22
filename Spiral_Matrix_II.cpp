#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)); // Initialize n x n matrix with 0s
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // Fill top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            ++top;

            // Fill right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            --right;

            // Fill bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                --bottom;
            }

            // Fill left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                ++left;
            }
        }

        return matrix;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    Solution solution;
    vector<vector<int>> result = solution.generateMatrix(n);

    cout << "Spiral Matrix:" << endl;
    printMatrix(result);

    return 0;
}