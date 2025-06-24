#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;

            // Greedily try to fit as many words as possible into the line
            while (last < n) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }

            string line;
            int numWords = last - index;
            int numSpaces = maxWidth - totalChars + (numWords - 1);

            // If it's the last line or only one word in this line
            if (last == n || numWords == 1) {
                for (int i = index; i < last; ++i) {
                    line += words[i];
                    if (i != last - 1) line += ' ';
                }
                // Fill remaining spaces to reach maxWidth
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int spacesPerSlot = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int i = index; i < last; ++i) {
                    line += words[i];
                    if (i != last - 1) {
                        // Distribute extra spaces to the leftmost slots
                        int spacesToInsert = spacesPerSlot + (i - index < extraSpaces ? 1 : 0);
                        line += string(spacesToInsert, ' ');
                    }
                }
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    // Call the text justification function
    vector<string> justifiedText = sol.fullJustify(words, maxWidth);

    // Print the result
    cout << "Justified Text:\n";
    for (const string& line : justifiedText) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}