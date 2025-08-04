#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefixSums(n + 1, 0);
        
        // Step 1: Build prefix sum array
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        // Step 2: Count range sums using modified merge sort
        return countWhileMergeSort(prefixSums, 0, n + 1, lower, upper);
    }

private:
    int countWhileMergeSort(vector<long>& sums, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;

        int mid = (left + right) / 2;
        int count = countWhileMergeSort(sums, left, mid, lower, upper) +
                    countWhileMergeSort(sums, mid, right, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long> cache(right - left);
        int r = 0;

        for (int i = left; i < mid; ++i) {
            // Find the valid range in [mid, right) where (sums[j] - sums[i]) in [lower, upper]
            while (k < right && sums[k] - sums[i] < lower) ++k;
            while (j < right && sums[j] - sums[i] <= upper) ++j;

            // Merge sort part: merge the two sorted halves
            while (t < right && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r++] = sums[i];

            count += j - k;
        }

        // Copy remaining elements
        while (t < right) cache[r++] = sums[t++];
        // Copy merged result back into the original array
        copy(cache.begin(), cache.begin() + r, sums.begin() + left);

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    int result = solution.countRangeSum(nums, lower, upper);
    cout << "Number of valid range sums: " << result << endl; 
    return 0;
}