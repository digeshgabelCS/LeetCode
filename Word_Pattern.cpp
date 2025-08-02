#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const string& w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } else {
                charToWord[c] = w;
            }

            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) return false;
            } else {
                wordToChar[w] = c;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    string pattern = "abba";
    string s = "dog cat cat dog";

    if (sol.wordPattern(pattern, s)) {
        cout << "The string follows the pattern." << endl;
    } else {
        cout << "The string does not follow the pattern." << endl;
    }

    return 0;
}