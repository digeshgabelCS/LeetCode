#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // counter for elements not equal to val

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3, 4, 2, 5};
    int val = 2;

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int k = solution.removeElement(nums, val);

    cout << "Number of elements not equal to " << val << ": " << k << endl;

    cout << "Modified array: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}