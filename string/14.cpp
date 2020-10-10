#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        int min = 0;
        for (string s : strs) {
            if (min < s.length())
                min = s.length();
        }
        string temp = strs[0];
        int substr = -1;
        for (int i = 0; i < min; i++) {
            for (string s : strs) {
                if (temp[i] != s[i]) {
                    substr = i;
                    break;
                }
            }
            if (substr >= 0)
                break;
        }
        return temp.substr(0, substr);
    }
};