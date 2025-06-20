#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if string s matches pattern p
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // DP table of size (m+1) x (n+1) initialized to false
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // If pattern starts with *, it can match empty string
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    // Characters match or pattern has '?'
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    // '*' can match zero characters (dp[i][j-1]) or one or more (dp[i-1][j])
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        
        // Final result at bottom-right of DP table
        return dp[m][n];
    }
};

// Main function to test the wildcard matching
int main() {
    Solution sol;

    // Test cases
    string s1 = "adceb";
    string p1 = "*a*b";
    cout << "Test 1: " << (sol.isMatch(s1, p1) ? "Match" : "No Match") << endl;

    string s2 = "acdcb";
    string p2 = "a*c?b";
    cout << "Test 2: " << (sol.isMatch(s2, p2) ? "Match" : "No Match") << endl;

    string s3 = "abc";
    string p3 = "a*?";
    cout << "Test 3: " << (sol.isMatch(s3, p3) ? "Match" : "No Match") << endl;

    string s4 = "aa";
    string p4 = "*";
    cout << "Test 4: " << (sol.isMatch(s4, p4) ? "Match" : "No Match") << endl;

    string s5 = "cb";
    string p5 = "?a";
    cout << "Test 5: " << (sol.isMatch(s5, p5) ? "Match" : "No Match") << endl;

    return 0;
}