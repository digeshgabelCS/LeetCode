#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;

        // Split the path by '/' and process each part
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty parts and '.' representing current directory
                continue;
            } else if (token == "..") {
                // '..' means move up a directory if possible
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                // Valid directory name — push it onto the stack
                st.push(token);
            }
        }

        // Build the simplified canonical path from the stack
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        // If the result is empty, it means root directory
        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.simplifyPath("/home/") << endl;               // Output: /home
    cout << sol.simplifyPath("/../") << endl;                 // Output: /
    cout << sol.simplifyPath("/home//foo/") << endl;          // Output: /home/foo
    cout << sol.simplifyPath("/a/./b/../../c/") << endl;      // Output: /c
    cout << sol.simplifyPath("/a//b////c/d//././/..") << endl;// Output: /a/b/c
    cout << sol.simplifyPath("/.../") << endl;                // Output: /...
    cout << sol.simplifyPath("/a/../../b/../c//.//") << endl; // Output: /c

    return 0;
}