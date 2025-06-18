#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
        long long res = 0;

        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            m -= t;
            res += p;
        }

        if ((dividend < 0) ^ (divisor < 0))
            res = -res;

        return res > INT_MAX ? INT_MAX : res;
    }
};

int main() {
    Solution solution;
    int dividend, divisor;

    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    int result = solution.divide(dividend, divisor);
    cout << "Quotient: " << result << endl;

    return 0;
}