#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // Sort the array to make it easier to avoid duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = nums[left] + nums[right];
                    if (sum == newTarget) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for left and right
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } 
                    else if (sum < newTarget) {
                        ++left;
                    } 
                    else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, target;

    // Input array size
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    // Input target value
    cout << "Enter target sum: ";
    cin >> target;

    // Get result
    vector<vector<int>> quadruplets = sol.fourSum(nums, target);

    cout << "Unique quadruplets:\n";
    for (const auto& quad : quadruplets) {
        cout << "[";
        for (int i = 0; i < 4; ++i) {
            cout << quad[i];
            if (i != 3) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}