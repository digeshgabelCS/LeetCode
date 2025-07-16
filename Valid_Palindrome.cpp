#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Move left pointer to next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Move right pointer to previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "Test 1: " << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // true
    cout << "Test 2: " << sol.isPalindrome("race a car") << endl;                     // false
    cout << "Test 3: " << sol.isPalindrome(" ") << endl;                              // true
    return 0;
}