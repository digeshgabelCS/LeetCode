#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to add two binary strings and return the result as a binary string
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.size() - 1;  // Pointer for string a
        int j = b.size() - 1;  // Pointer for string b

        // Loop through both strings from end to start
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';  // Convert char to int and add
            if (j >= 0) sum += b[j--] - '0';

            carry = sum / 2;                      // Update carry
            result += (sum % 2) + '0';            // Append the result bit as char
        }

        // Since we appended bits from least significant to most, reverse the string
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string a = "1010";
    string b = "1011";
    
    string sum = sol.addBinary(a, b);
    cout << "Sum: " << sum << endl;  

    return 0;
}