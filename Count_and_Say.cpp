#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  // Base case

        string result = "1";

        for (int i = 2; i <= n; ++i) {
            string current = "";
            int count = 1;
            char prevChar = result[0];

            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == prevChar) {
                    count++;
                } else {
                    current += to_string(count) + prevChar;
                    prevChar = result[j];
                    count = 1;
                }
            }

            // Append the last run
            current += to_string(count) + prevChar;

            result = current;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    string result = solution.countAndSay(n);
    cout << "The " << n << "th element of the count-and-say sequence is: " << result << endl;

    return 0;
}
