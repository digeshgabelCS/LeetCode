#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        // Group words by their sorted string as key
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sort characters in string
            anagramGroups[key].push_back(s);
        }

        // Prepare result from the map
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> groupedAnagrams = solution.groupAnagrams(input);

    // Print the result
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : groupedAnagrams) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}