#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to compute sum of squares of digits
    int getNext(int n) {
        int total = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            total += d * d;
        }
        return total;
    }

    bool isHappy(int n) {
        unordered_set<int> seen; // to detect cycles
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

// Example usage
int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (sol.isHappy(n))
        cout << n << " is a Happy Number ✅" << endl;
    else
        cout << n << " is NOT a Happy Number ❌" << endl;

    return 0;
}