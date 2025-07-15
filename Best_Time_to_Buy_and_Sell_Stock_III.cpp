#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> leftProfit(n, 0);  
        vector<int> rightProfit(n, 0); 

        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i-1], prices[i] - minPrice);
        }

        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i+1], maxPrice - prices[i]);
        }

        int maxTotalProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxTotalProfit = max(maxTotalProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxTotalProfit;
    }
};

int main() {
    Solution solution;

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int result = solution.maxProfit(prices);

    cout << "Maximum Profit with at most two transactions: " << result << endl;

    return 0;
}