#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        long long res = 1;
        int N = m + n - 2; // total moves
        int k = m - 1;     // number of down moves (could also use n-1)

        // since C(N, k) == C(N, N-k)
        if (k > N - k) k = N - k;

        for (int i = 1; i <= k; ++i) {
            res = res * (N - k + i) / i;
        }

        return (int)res;
    }
};

int main() {
    Solution sol;
    int m, n;

    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int result = sol.uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}