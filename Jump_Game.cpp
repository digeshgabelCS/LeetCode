#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {

                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "Test case 1: ";
    if (sol.canJump(nums1))
        cout << "Can reach the end." << endl;
    else
        cout << "Cannot reach the end." << endl;

    cout << "Test case 2: ";
    if (sol.canJump(nums2))
        cout << "Can reach the end." << endl;
    else
        cout << "Cannot reach the end." << endl;

    return 0;
}