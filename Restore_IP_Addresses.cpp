#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(const string& s, int start, int dots, string currentIP, vector<string>& result) {
        if (dots == 4 && start == s.size()) {
            result.push_back(currentIP.substr(0, currentIP.size() - 1)); 
            return;
        }
        if (dots > 4) return;

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;

            string part = s.substr(start, len);

            if ((part.size() > 1 && part[0] == '0') || stoi(part) > 255) continue;

            backtrack(s, start + len, dots + 1, currentIP + part + '.', result);
        }
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;

    vector<string> validIPs = sol.restoreIpAddresses(input);

    cout << "Valid IP addresses:\n";
    for (const string& ip : validIPs) {
        cout << ip << endl;
    }

    return 0;
}