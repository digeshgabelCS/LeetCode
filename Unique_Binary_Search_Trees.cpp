#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // An empty tree is considered one BST
        dp[1] = 1;  // One node tree is one BST

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

// Optional: Main function to test the solution
int main() {
    Solution solution;
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    int result = solution.numTrees(n);
    cout << "Number of unique BSTs with " << n << " nodes: " << result << endl;

    return 0;
}
