#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting or ending cell is an obstacle, no paths exist.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        // DP table to store number of ways to reach each cell
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;  // Starting point

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;  // No paths through obstacles
                } else {
                    if (i > 0)
                        dp[i][j] += dp[i-1][j];
                    if (j > 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution solution;

    // Example grid: 0 = free, 1 = obstacle
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
