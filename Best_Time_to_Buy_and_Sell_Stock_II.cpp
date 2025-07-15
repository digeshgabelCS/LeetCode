#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution solution;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int profit = solution.maxProfit(prices);

    cout << "Maximum Profit: " << profit << endl;

    return 0;
}