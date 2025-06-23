#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;

        // Trim leading spaces
        while (i < n && s[i] == ' ') i++;
        if (i == n) return false;

        // Trim trailing spaces
        int j = n - 1;
        while (j >= 0 && s[j] == ' ') j--;

        // Flags for digits, dot, exponent
        bool numSeen = false, dotSeen = false, eSeen = false, numAfterE = true;

        for (int k = i; k <= j; k++) {
            char c = s[k];

            if (isdigit(c)) {
                numSeen = true;
                if (eSeen) numAfterE = true;
            } 
            else if (c == '+' || c == '-') {
                // Sign must be at the start or just after e/E
                if (k != i && s[k-1] != 'e' && s[k-1] != 'E') return false;
            } 
            else if (c == '.') {
                // Only one dot allowed, and not after e/E
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            } 
            else if (c == 'e' || c == 'E') {
                // Only one e/E allowed, must follow a number
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numAfterE = false;  // must be followed by a number
            } 
            else {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;  // Print 'true' or 'false' instead of 1/0

    // Test cases
    cout << "53.5e93: " << sol.isNumber("53.5e93") << endl;  // true
    cout << "e3: " << sol.isNumber("e3") << endl;            // false
    cout << "99e2.5: " << sol.isNumber("99e2.5") << endl;    // false
    cout << "2e10: " << sol.isNumber("2e10") << endl;        // true
    cout << "-90E3: " << sol.isNumber("-90E3") << endl;      // true
    cout << "1a: " << sol.isNumber("1a") << endl;            // false
    cout << "   4. : " << sol.isNumber("   4. ") << endl;   // true
    cout << " -123.456e789: " << sol.isNumber(" -123.456e789") << endl; // true
    cout << "--6: " << sol.isNumber("--6") << endl;          // false
    cout << "+3.14: " << sol.isNumber("+3.14") << endl;      // true

    return 0;
}