#include <iostream>
using namespace std;

int badVersion = 4; 

bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        while (left < right) {
            int mid = left + (right - left) / 2; 
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1; 
            }
        }

        return left; 
    }
};

int main() {
    Solution solution;
    int n = 10; 
    cout << "First bad version is: " << solution.firstBadVersion(n) << endl;
    return 0;
}