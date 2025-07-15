#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }

        return triangle[0][0];
    }
};

int main() {
    Solution sol;
 
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int result = sol.minimumTotal(triangle);
    cout << "Minimum path total: " << result << endl;

    return 0;
}