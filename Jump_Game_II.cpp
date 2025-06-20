#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // when we reach the end of the current jump range
            if (i == currentEnd) {
                ++jumps;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};

    int result = solution.jump(nums);
    cout << "Minimum number of jumps to reach the end: " << result << endl;

    return 0;
}