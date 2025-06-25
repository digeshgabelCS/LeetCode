#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current.push_back(i);                 
            backtrack(i + 1, n, k, current, result);  
            current.pop_back();                   
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2;

    vector<vector<int>> combinations = sol.combine(n, k);

    cout << "Combinations of " << k << " numbers from 1 to " << n << ":\n";
    for (const auto& combination : combinations) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i != combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}