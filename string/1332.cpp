#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty())
            return 0;
        int i = 0;
        int len = s.length();
        while (i < len / 2) {
            if (s[i] != s[len - i - 1])
                return 2;
            i++;
        }
        return 1;
    }
};
