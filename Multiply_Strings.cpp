#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // If either number is "0", the result is "0"
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);

        // Multiply each digit of num1 and num2
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert result vector to string
        string product = "";
        int i = 0;

        // Skip leading zeros
        while (i < result.size() && result[i] == 0) ++i;

        while (i < result.size())
            product.push_back(result[i++] + '0');

        return product;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string num1 = "123";
    string num2 = "456";
    cout << "Product of " << num1 << " and " << num2 << " is: " 
         << sol.multiply(num1, num2) << endl;  // Expected: 56088

    // Example 2
    num1 = "999";
    num2 = "999";
    cout << "Product of " << num1 << " and " << num2 << " is: " 
         << sol.multiply(num1, num2) << endl;  // Expected: 998001

    // Example 3
    num1 = "0";
    num2 = "123456";
    cout << "Product of " << num1 << " and " << num2 << " is: " 
         << sol.multiply(num1, num2) << endl;  // Expected: 0

    return 0;
}