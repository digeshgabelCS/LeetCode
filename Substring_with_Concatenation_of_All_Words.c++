#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        if (s.size() < totalLength) return result;

        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordLength; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> windowFreq;

            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordFreq.count(word)) {
                    windowFreq[word]++;
                    count++;

                    while (windowFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        windowFreq[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
            
                    windowFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> indices = solution.findSubstring(s, words);

    cout << "Starting indices of concatenated substrings: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}