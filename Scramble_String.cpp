#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        // Base cases
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        // Check if both strings have same characters (pruning)
        string sorted_s1 = s1, sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2) return false;

        string key = s1 + "#" + s2;
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.length();
        for (int i = 1; i < n; ++i) {
            // Without swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            // With swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};

int main() {
    Solution solution;

    // Example test cases
    string s1 = "great", s2 = "rgeat";
    cout << "Is \"" << s2 << "\" a scramble of \"" << s1 << "\"? "
         << (solution.isScramble(s1, s2) ? "Yes" : "No") << endl;

    s1 = "abcde";
    s2 = "caebd";
    cout << "Is \"" << s2 << "\" a scramble of \"" << s1 << "\"? "
         << (solution.isScramble(s1, s2) ? "Yes" : "No") << endl;

    return 0;
}
