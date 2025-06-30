#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, result);
            subset.pop_back();  
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());  
        backtrack(nums, 0, subset, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}