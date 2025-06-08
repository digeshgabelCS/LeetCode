#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] = true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Initialize first row (when s is empty)
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // Characters match or '.' wildcard
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Zero occurrence of the character before '*'
                    dp[i][j] = dp[i][j - 2];
                    
                    // Or one/more occurrence if preceding character matches current s character
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "aab";
    string p1 = "c*a*b";
    cout << "Test case 1: " << (solution.isMatch(s1, p1) ? "true" : "false") << endl;
    
    // Test case 2
    string s2 = "mississippi";
    string p2 = "mis*is*p*.";
    cout << "Test case 2: " << (solution.isMatch(s2, p2) ? "true" : "false") << endl;
    
    // Test case 3
    string s3 = "ab";
    string p3 = ".*";
    cout << "Test case 3: " << (solution.isMatch(s3, p3) ? "true" : "false") << endl;

    return 0;
}