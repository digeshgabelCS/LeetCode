#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; 

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current); 
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> current;
        backtrack(candidates, target, 0, current);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> combinations = sol.combinationSum2(candidates, target);

    cout << "Combinations summing to " << target << " are:\n";
    for (const auto& comb : combinations) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}