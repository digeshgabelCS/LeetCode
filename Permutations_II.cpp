#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        // Sort to handle duplicates
        sort(nums.begin(), nums.end());

        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip used elements
            if (used[i]) continue;

            // Skip duplicates: if the number is the same as the previous and the previous hasn't been used
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "Unique permutations are:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}