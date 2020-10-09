#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int forward = 0;
        int backward = s.length() - 1;
        while (forward < backward) {
            if (isVowel(s[forward]) && isVowel(s[backward])) {
                char temp = s[forward];
                s[forward] = s[backward];
                s[backward] = temp;
                ++forward;
                --backward;
            }
            if (!isVowel(s[forward]) && !isVowel(s[backward])) {
                ++forward;
                --backward;
            }
            if (!isVowel(s[forward]) && isVowel(s[backward])) {
                ++forward;
            }
            if (isVowel(s[forward]) && !isVowel(s[backward])) {
                --backward;
            }
        }
        return s;
    }
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};
