#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0]; 

        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                start = nums[i]; 
            }
        }

        if (start == nums[n - 1]) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 2, 4, 5, 7};

    vector<string> ranges = sol.summaryRanges(nums);

    cout << "Summary Ranges:" << endl;
    for (const string& range : ranges) {
        cout << range << endl;
    }

    return 0;
}