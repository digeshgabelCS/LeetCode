#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            int currentValue = romanValues[s[i]];
            
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            
            prevValue = currentValue;
        }

        return total;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("MCMXCIV") << endl;  // Output should be 1994
    return 0;
}