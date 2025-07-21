#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example inputs
    string input1 = "A";
    string input2 = "Z";
    string input3 = "AA";
    string input4 = "AB";
    string input5 = "ZY";

    // Output results
    cout << "Column " << input1 << " = " << sol.titleToNumber(input1) << endl;
    cout << "Column " << input2 << " = " << sol.titleToNumber(input2) << endl;
    cout << "Column " << input3 << " = " << sol.titleToNumber(input3) << endl;
    cout << "Column " << input4 << " = " << sol.titleToNumber(input4) << endl;
    cout << "Column " << input5 << " = " << sol.titleToNumber(input5) << endl;

    return 0;
}