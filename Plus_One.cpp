#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Iterate from the last digit to the first
        for (int i = n - 1; i >= 0; --i) {
            // If current digit is less than 9, just add 1 and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If digit is 9, set it to 0 and continue to next digit
            digits[i] = 0;
        }

        // If all digits were 9, we reach here
        // Insert 1 at the beginning of the vector
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> digits = {9, 9, 9};

    // Call plusOne function
    vector<int> result = sol.plusOne(digits);

    // Print the result
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
