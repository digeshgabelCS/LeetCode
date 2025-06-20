#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination, i);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, result, combination, 0);
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}