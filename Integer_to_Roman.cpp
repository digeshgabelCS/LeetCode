#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Vector holding Roman numeral symbols and their corresponding values
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string result = "";

        // Iterate over the value-symbol pairs
        for (size_t i = 0; i < valueSymbols.size(); ++i) {
            while (num >= valueSymbols[i].first) {
                result += valueSymbols[i].second; // Append the symbol to result
                num -= valueSymbols[i].first;     // Subtract the value from num
            }
        }

        return result; // Return the final Roman numeral string
    }
};

int main() {
    Solution solution;
    int num;

    // Input from user
    cout << "Enter an integer to convert to Roman numeral: ";
    cin >> num;

    // Check for valid range (1 to 3999, as per typical Roman numeral rules)
    if (num < 1 || num > 3999) {
        cout << "Please enter a number between 1 and 3999." << endl;
        return 1;
    }

    // Convert and output the Roman numeral
    string romanNumeral = solution.intToRoman(num);
    cout << "Roman numeral: " << romanNumeral << endl;

    return 0;
}