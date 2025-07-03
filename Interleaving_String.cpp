#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size(), n = s2.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);

        for (int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                           (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;

    string s1 = "abc";
    string s2 = "def";
    string s3 = "adbcef";

    if (solution.isInterleave(s1, s2, s3))
        cout << s3 << " is an interleaving of " << s1 << " and " << s2 << endl;
    else
        cout << s3 << " is NOT an interleaving of " << s1 << " and " << s2 << endl;

    return 0;
}