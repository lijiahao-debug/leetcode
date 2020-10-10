#include <iostream>
#include <string>
#include <vector>

/*  
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            else if(tolower(s[left])!=tolower(s[right])) return false;
            else {left++; right--;}
        }
        return true;
    }
*/
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (!len)
            return true;
        int forward = 0;
        int backward = len - 1;
        int space = 0;

        while (forward < backward) {
            if (isAlphaNumeric(s[forward]) && isAlphaNumeric(s[backward])) {
                if (tolower(s[forward]) != tolower(s[backward]))
                    return false;
                ++forward;
                --backward;
            } else if (isAlphaNumeric(s[forward])) {
                --backward;
            } else if (isAlphaNumeric(s[backward])) {
                ++forward;
            } else {
                ++space;
                ++space;
                ++forward;
                --backward;
            }
        }
        if (space == len)
            return true;
        if (forward == len / 2 && space == len - 1) {
            if (!isAlphaNumeric(s[forward]))
                return true;
        }
        return true;
    }
    bool isAlphaNumeric(char c) {
        if (c >= '0' && c <= '9')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("8V8K;G;K;V;") << endl;
    cout << s.isPalindrome("    ") << endl;
    cout << s.isPalindrome("     ") << endl;
    return 0;
}