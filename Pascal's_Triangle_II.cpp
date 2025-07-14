#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1; 

        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    int rowIndex;

    cout << "Enter row index for Pascal's Triangle: ";
    cin >> rowIndex;

    vector<int> result = solution.getRow(rowIndex);

    cout << "Pascal's Triangle Row " << rowIndex << ": ";
    printVector(result);

    return 0;
}