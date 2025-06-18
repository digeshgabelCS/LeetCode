#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } 
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        
        return -1; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = solution.search(nums, target);
    if (index != -1)
        cout << "Target " << target << " found at index " << index << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}