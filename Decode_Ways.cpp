#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;  
        dp[1] = 1;  

        for (int i = 2; i <= n; ++i) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    string s1 = "11106";
    string s2 = "226";
    string s3 = "06";
    string s4 = "12";

    cout << "Number of ways to decode '" << s1 << "' = " << solution.numDecodings(s1) << endl;
    cout << "Number of ways to decode '" << s2 << "' = " << solution.numDecodings(s2) << endl;
    cout << "Number of ways to decode '" << s3 << "' = " << solution.numDecodings(s3) << endl;
    cout << "Number of ways to decode '" << s4 << "' = " << solution.numDecodings(s4) << endl;

    return 0;
}