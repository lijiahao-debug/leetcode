#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        int len = pattern.length();
        if (len == 1) {
            return words;
        }

        map<char, int> m1, m2;
        vector<string> ret;
        for (string w : words) {
            m1.clear();
            m2.clear();
            bool flag = true;
            for (int i = 0; i < len; i++) {
                if (m1.find(w[i]) == m1.end()) {
                    m1[w[i]] = pattern[i];
                }
                if (m2.find(pattern[i]) == m2.end()) {
                    m2[pattern[i]] = w[i];
                }
                if (m1[w[i]] != pattern[i] || m2[pattern[i]] != w[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ret.push_back(w);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    vector<string> ret = sol.findAndReplacePattern(words, "abb");
    for (string s : ret) {
        cout << s << endl;
    }
    return 0;
}