#include <iostream>
#include <climits>  // for INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Check for overflow before multiplying and adding
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
            
            result = result * 10 + digit;
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    int number;
    cout << "Enter a number to reverse: ";
    cin >> number;
    
    int reversedNumber = solution.reverse(number);
    
    cout << "Reversed number: " << reversedNumber << endl;
    
    return 0;
}