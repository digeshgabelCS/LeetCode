#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  
            char ch = 'A' + (columnNumber % 26);
            result = ch + result;  
            columnNumber /= 26;
        }
        return result;
    }
};

int main() {
    Solution solution;

    int test1 = 1;
    int test2 = 28;
    int test3 = 701;
    int test4 = 2147483647; 
    
    cout << "Column number " << test1 << " -> " << solution.convertToTitle(test1) << endl;
    cout << "Column number " << test2 << " -> " << solution.convertToTitle(test2) << endl;
    cout << "Column number " << test3 << " -> " << solution.convertToTitle(test3) << endl;
    cout << "Column number " << test4 << " -> " << solution.convertToTitle(test4) << endl;

    return 0;
}