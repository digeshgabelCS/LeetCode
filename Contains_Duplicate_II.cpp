#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index_map; 

        for (int i = 0; i < nums.size(); ++i) {
            if (index_map.find(nums[i]) != index_map.end()) {
                if (i - index_map[nums[i]] <= k) {
                    return true;
                }
            }
            index_map[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    bool result = sol.containsNearbyDuplicate(nums, k);

    if (result) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}