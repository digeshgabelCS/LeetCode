#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Iterate character by character over the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            // Compare this character with the same position in other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If position exceeds current string length, or mismatch occurs, return prefix up to i
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        // If no mismatch, the whole first string is the prefix
        return strs[0];
    }
};

int main() {
    Solution solution;

    // Example test case
    vector<string> strs = {"flower", "flow", "flight"};

    // Call the function and print the result
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;

    return 0;
}