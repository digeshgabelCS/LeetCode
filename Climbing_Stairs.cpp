#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int first = 1;
        int second = 2;
        int current = 0;

        for (int i = 3; i <= n; ++i) {
            current = first + second;
            first = second;
            second = current;
        }

        return second;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter number of steps: ";
    cin >> n;

    int ways = solution.climbStairs(n);
    cout << "Number of distinct ways to climb to the top: " << ways << endl;

    return 0;
}
