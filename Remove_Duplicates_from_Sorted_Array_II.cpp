#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If 2 or fewer elements, nothing to remove

        int insertPos = 2; // Start from index 2 because first two are always allowed

        for (int i = 2; i < n; ++i) {
            // Compare current element with the element two places before
            if (nums[i] != nums[insertPos - 2]) {
                nums[insertPos] = nums[i];
                ++insertPos;
            }
        }

        return insertPos;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = solution.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}