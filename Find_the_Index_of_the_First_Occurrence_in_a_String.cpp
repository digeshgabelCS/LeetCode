#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;  

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;  
        }

        return -1; 
    }
};

int main() {
    Solution sol;
    string haystack, needle;

    cout << "Enter the haystack string: ";
    getline(cin, haystack);

    cout << "Enter the needle string: ";
    getline(cin, needle);

    int index = sol.strStr(haystack, needle);

    if (index != -1) {
        cout << "The first occurrence of \"" << needle << "\" in \"" << haystack << "\" is at index: " << index << endl;
    } else {
        cout << "The needle \"" << needle << "\" was not found in the haystack \"" << haystack << "\"." << endl;
    }

    return 0;
}