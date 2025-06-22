#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
            fact *= i;
        }

        k--;

        string result = "";

        for (int i = 0; i < n; ++i) {
            fact = fact / (n - i);
            int index = k / fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k = k % fact;
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n, k;

    cout << "Enter value of n: ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    string kth_permutation = sol.getPermutation(n, k);
    cout << "The " << k << "th permutation sequence is: " << kth_permutation << endl;

    return 0;
}