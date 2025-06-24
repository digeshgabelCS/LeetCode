#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;  // quick return for 0 and 1

        int left = 1, right = x / 2, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int x;

    cout << "Enter a non-negative integer: ";
    cin >> x;

    int result = solution.mySqrt(x);
    cout << "The integer part of the square root of " << x << " is: " << result << endl;

    return 0;
}