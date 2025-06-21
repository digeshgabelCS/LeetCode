#include <iostream>
#include <limits> 
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << "2^10 = " << sol.myPow(2.0, 10) << endl;     // Expected: 1024
    cout << "2^-2 = " << sol.myPow(2.0, -2) << endl;     // Expected: 0.25
    cout << "3^5 = " << sol.myPow(3.0, 5) << endl;       // Expected: 243
    cout << "5^0 = " << sol.myPow(5.0, 0) << endl;       // Expected: 1
    cout << "2^-3 = " << sol.myPow(2.0, -3) << endl;     // Expected: 0.125
    cout << "(-2)^3 = " << sol.myPow(-2.0, 3) << endl;   // Expected: -8

    return 0;
}