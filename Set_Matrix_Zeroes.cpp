#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Check if first row has any zero
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // Use first row and column to mark zeros
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros based on marks
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out first row if needed
        if (firstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Zero out first column if needed
        if (firstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

// Example usage
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution sol;
    sol.setZeroes(matrix);

    // Print modified matrix
    cout << "Modified Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
