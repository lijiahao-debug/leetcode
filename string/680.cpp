#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        int left = 0;
        int right = len - 1;
        int count = 0;
        while (right - left >= 2) {
            if (count >= 2) {
                cout << "count = " << count << endl;
                return false;
            }
            if (s[right] == s[left]) {
                ++left;
                --right;
            } else if (s[left + 1] == s[right] && s[left] == s[right - 1]) {
                ++left;
                --right;
            } else if (s[left + 1] == s[right]) {
                ++count;
                ++left;
            } else if (s[left] == s[right - 1]) {
                ++count;
                --right;
            } else {
                return false;
            }
        }
        return count > 1 ? false : true;
    }
};

int main() {
    Solution sol;
    cout << sol.validPalindrome("aabdeenddbaagbddeedbaa") << endl;
    cout << sol.validPalindrome("dmysgvhmvvmhvgsymdp") << endl;
    cout << sol.validPalindrome("puufxxfuupu") << endl;
    return 0;
}