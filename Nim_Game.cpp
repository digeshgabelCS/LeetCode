#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution sol;

    int test1 = 4;
    int test2 = 7;
    int test3 = 10;

    cout << "Can win with " << test1 << " stones? " << (sol.canWinNim(test1) ? "Yes" : "No") << endl;
    cout << "Can win with " << test2 << " stones? " << (sol.canWinNim(test2) ? "Yes" : "No") << endl;
    cout << "Can win with " << test3 << " stones? " << (sol.canWinNim(test3) ? "Yes" : "No") << endl;

    return 0;
}