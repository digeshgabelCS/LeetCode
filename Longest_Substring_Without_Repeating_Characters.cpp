#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // If character is found in map and its index is >= start of current window
            if (charIndex.find(currentChar) != charIndex.end()) {
                start = max(start, charIndex[currentChar] + 1);
            }

            // Update the index of the current character
            charIndex[currentChar] = end;

            // Update maximum length if current window is larger
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    int result = solution.lengthOfLongestSubstring(input);

    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}