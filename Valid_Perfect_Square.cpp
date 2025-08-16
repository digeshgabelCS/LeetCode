#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true; 

        long long left = 1, right = num / 2;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;

            if (sq == num) return true;
            else if (sq < num) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> testCases = {1, 4, 9, 14, 16, 25, 26, 100, 2147395600};

    for (int num : testCases) {
        cout << "num = " << num 
             << " -> " << (sol.isPerfectSquare(num) ? "true" : "false") 
             << endl;
    }

    return 0;
}