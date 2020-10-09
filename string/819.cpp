#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        map<string, int> table;
        int len = paragraph.length();
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), [](unsigned char c) { return tolower(c); });
        int index = 0;
        map<string, int>::iterator iter;
        for (int i = 0; i < len; i++) {
            if (!isalpha(paragraph[i]) || i == len - 1) {
                if (i == len - 1 && isalpha(paragraph[i])) {
                    ++i;
                }
                if (i - index > 0) {
                    string word = paragraph.substr(index, i - index);
                    if (find(banned.begin(), banned.end(), word) == banned.end()) {
                        iter = table.find(word);
                        if (iter != table.end()) {
                            iter->second += 1;
                        } else {
                            table.insert(pair<string, int>(word, 1));
                        }
                    }
                }
                index = i + 1;
            }
        }
        int max = 0;
        string ret = "";
        for (iter = table.begin(); iter != table.end(); iter++) {
            if (max < iter->second) {
                max = iter->second;
                ret = iter->first;
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<string> v = {"hit"};
    cout << s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v) << endl;
    cout << s.mostCommonWord("Bob", v) << endl;

    return 0;
}