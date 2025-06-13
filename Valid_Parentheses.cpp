#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // If it's a closing bracket, check for a matching opening bracket
            else {
                if (st.empty()) return false; // No matching opening bracket

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false; // Mismatched pair
                }
            }
        }

        // If stack is empty at the end, all brackets matched
        return st.empty();
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string containing brackets: ";
    cin >> s;

    if (solution.isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}