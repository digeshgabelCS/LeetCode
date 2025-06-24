#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // Create a DP table of size (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize the base cases
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;  // Deleting all characters from word1

        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;  // Inserting all characters of word2

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // No operation needed
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // Delete
                        dp[i][j - 1],    // Insert
                        dp[i - 1][j - 1] // Replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    int result = solution.minDistance(word1, word2);
    cout << "Minimum edit distance: " << result << endl;

    return 0;
}