#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapping;       // s -> t
        unordered_set<char> mapped_characters;   // already used characters in t

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapping.count(c1)) {
                if (mapping[c1] != c2) return false;
            } else {
                if (mapped_characters.count(c2)) return false;
                mapping[c1] = c2;
                mapped_characters.insert(c2);
            }
        }
        return true;
    }
};

// Example usage
int main() {
    Solution sol;

    string s1 = "egg", t1 = "add";
    string s2 = "foo", t2 = "bar";
    string s3 = "paper", t3 = "title";

    cout << boolalpha; // to print true/false instead of 1/0
    cout << "Isomorphic(\"" << s1 << "\", \"" << t1 << "\"): " << sol.isIsomorphic(s1, t1) << endl;
    cout << "Isomorphic(\"" << s2 << "\", \"" << t2 << "\"): " << sol.isIsomorphic(s2, t2) << endl;
    cout << "Isomorphic(\"" << s3 << "\", \"" << t3 << "\"): " << sol.isIsomorphic(s3, t3) << endl;

    return 0;
}
