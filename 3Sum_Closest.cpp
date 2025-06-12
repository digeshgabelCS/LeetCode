#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // Sort the array
        sort(nums.begin(), nums.end());

        // Initialize closest sum with the sum of first three numbers
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // If this is closer to target, update closestSum
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Move pointers based on comparison
                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    // Exact match found
                    return target;
                }
            }
        }

        return closestSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, target;

    // Input number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    // Input target value
    cout << "Enter target value: ";
    cin >> target;

    // Call function and print result
    int result = sol.threeSumClosest(nums, target);
    cout << "The closest sum to target is: " << result << endl;

    return 0;
}