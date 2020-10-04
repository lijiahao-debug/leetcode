#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        int len = logs.size();
        if (len < 2)
            return logs;
        map<string, string> letter_logs;
        vector<string> digit_logs;

        for (string s : logs) {
            int first_word = s.find(' ') + 1;
            if (isalpha(s[first_word])) {
                letter_logs.insert({s.substr(first_word) + s.substr(0, first_word), s});
            } else {
                digit_logs.push_back(s);
            }
        }
        vector<string> ret;
        for (auto x : letter_logs) {
            ret.push_back(x.second);
        }
        ret.insert(ret.end(), digit_logs.begin(), digit_logs.end());
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> test;
    // a1 9 2 3 1
    // g1 act car
    // zo4 4 7
    // ab1 off key dog
    // a8 act zoo
    // a2 act car
    test.push_back("a1 9 2 3 1");
    test.push_back("g1 act car");
    test.push_back("zo4 4 7");
    test.push_back("ab1 off key dog");
    test.push_back("a8 act zoo");
    test.push_back("a2 act car");

    vector<string> ret = s.reorderLogFiles(test);
    for (auto &it : ret) {
        cout << it << endl;
    }
    return 0;
}