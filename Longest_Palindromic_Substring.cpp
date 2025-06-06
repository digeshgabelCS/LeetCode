#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;

        int start = 0, maxLength = 1;

        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < s.length(); ++i) {
            // Check for odd-length palindrome (single center)
            expandFromCenter(i, i);
            // Check for even-length palindrome (double center)
            expandFromCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string result = solution.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}