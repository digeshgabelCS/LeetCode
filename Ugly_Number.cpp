#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // Ugly numbers are positive

        // Divide by 2, 3, and 5 as long as possible
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        // If we end up with 1, it only had 2, 3, and 5 as prime factors
        return n == 1;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int test[] = {6, 8, 14, 1, 0, -6};
    for (int n : test) {
        cout << "Is " << n << " an ugly number? " 
             << (solution.isUgly(n) ? "Yes" : "No") << endl;
    }

    return 0;
}