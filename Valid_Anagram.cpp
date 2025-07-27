#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> count;

        for (char c : s)
            count[c]++;

        for (char c : t) {
            if (count.find(c) == count.end() || count[c] == 0)
                return false;
            count[c]--;
        }

        return true;
    }  
};

int main() {
    Solution solution;

    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Test 1: " << (solution.isAnagram(s1, t1) ? "True" : "False") << endl;

    string s2 = "rat";
    string t2 = "car";
    cout << "Test 2: " << (solution.isAnagram(s2, t2) ? "True" : "False") << endl;

    string s3 = "listen";
    string t3 = "silent";
    cout << "Test 3: " << (solution.isAnagram(s3, t3) ? "True" : "False") << endl;

    return 0;
}