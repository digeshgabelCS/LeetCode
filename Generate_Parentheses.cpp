#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // If the current string is complete
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // If we can add an opening parenthesis
        if (open < max) {
            backtrack(result, current + '(', open + 1, close, max);
        }

        // If we can add a closing parenthesis
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, max);
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);

    cout << "Well-formed combinations are:\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}