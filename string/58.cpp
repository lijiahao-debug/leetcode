#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int len = s.length();
        if (!len)
            return ret;
        int i = len - 1;
        while (i) {
            if (ret && s[i] == ' ')
                return ret;
            if (isalpha(s[i]))
                ret++;
            --i;
        }
        return isalpha(s[0]) ? ret + 1 : ret;
    }
};