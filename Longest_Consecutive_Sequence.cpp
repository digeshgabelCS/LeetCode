#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    
    Solution sol;
    int result = sol.longestConsecutive(nums);
    
    cout << "Length of longest consecutive sequence: " << result << endl;
    return 0;
}