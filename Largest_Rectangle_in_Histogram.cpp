#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights of bars: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    Solution sol;
    int result = sol.largestRectangleArea(heights);

    cout << "Largest rectangle area is: " << result << endl;

    return 0;
}