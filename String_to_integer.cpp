#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits to integer
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // 4. Clamp if out of 32-bit signed int range
            if (sign == 1 && result >= INT_MAX) return INT_MAX;
            if (sign == -1 && -result <= INT_MIN) return INT_MIN;
            
            i++;
        }

        // 5. Apply sign and return
        result *= sign;
        return static_cast<int>(result);
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("42") << endl;                 // Output: 42
    cout << sol.myAtoi("   -42") << endl;             // Output: -42
    cout << sol.myAtoi("4193 with words") << endl;    // Output: 4193
    cout << sol.myAtoi("words and 987") << endl;      // Output: 0
    cout << sol.myAtoi("-91283472332") << endl;       // Output: -2147483648
    cout << sol.myAtoi("91283472332") << endl;        // Output: 2147483647
    cout << sol.myAtoi("+00000123") << endl;          // Output: 123
    cout << sol.myAtoi("   +0 123") << endl;          // Output: 0
    return 0;
}