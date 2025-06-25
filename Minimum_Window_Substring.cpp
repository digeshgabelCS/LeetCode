#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> t_count;
        for (char c : t) {
            t_count[c]++;
        }

        int required = t_count.size();
        int formed = 0;
        unordered_map<char, int> window_count;

        int left = 0, right = 0;
        int min_len = INT_MAX, min_left = 0;

        while (right < s.size()) {
            char c = s[right];
            window_count[c]++;

            if (t_count.count(c) && window_count[c] == t_count[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }

                char ch = s[left];
                window_count[ch]--;

                if (t_count.count(ch) && window_count[ch] < t_count[ch]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};

int main() {
    Solution solution;
    string s, t;

    cout << "Enter string s: ";
    getline(cin, s);

    cout << "Enter string t: ";
    getline(cin, t);

    string result = solution.minWindow(s, t);

    if (result.empty()) {
        cout << "No valid window found." << endl;
    } else {
        cout << "Minimum window substring: " << result << endl;
    }

    return 0;
}