#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n; // 2^n

        for (int i = 0; i < size; ++i) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of bits (n): ";
    cin >> n;

    Solution solution;
    vector<int> grayCodes = solution.grayCode(n);

    cout << "Gray Code Sequence for " << n << " bits:" << endl;
    for (int num : grayCodes) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}