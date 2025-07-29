#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        return 1 + (num - 1) % 9;
    }
};

int main() {
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = solution.addDigits(num);
    cout << "Result after repeatedly adding digits: " << result << endl;

    return 0;
}