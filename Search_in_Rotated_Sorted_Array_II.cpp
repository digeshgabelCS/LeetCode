#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Found the target
            if (nums[mid] == target) {
                return true;
            }

            // If we can't be sure which side is sorted because of duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            }
            // Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // target in left half
                } else {
                    left = mid + 1;  // target in right half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // target in right half
                } else {
                    right = mid - 1; // target in left half
                }
            }
        }

        return false; // Not found
    }
};

// Test driver
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
    int target = 0;

    if (sol.search(nums, target)) {
        cout << "Target " << target << " found in array." << endl;
    } else {
        cout << "Target " << target << " not found in array." << endl;
    }

    return 0;
}
