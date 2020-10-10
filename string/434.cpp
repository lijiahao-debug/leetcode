#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        if (!len)
            return 0;
        int ret = 0;
        for (int i = 1; i < len; i++) {
            if (s[i - 1] != ' ' && s[i] == ' ')
                ++ret;
        }
        if (s[len - 1] != ' ')
            ++ret;
        return ret;
    }
};