#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings1(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j + i <= s.length(); j++) {
                if (isPalindromic(s.substr(i, j))) {
                    ++ret;
                }
            }
        }
        return ret;
    }

private:
    bool isPalindromic(string subString) {
        int i = 0;
        int j = subString.length() - 1;
        while (i < j) {
            if (subString[i] != subString[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }

public:
    /* dynamic programming
    aabaaba
    */
    int countSubstrings(string s) {
        int ret = 0;
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            ++ret;
        }
        for (int col = 1; col < len; col++) {
            for (int row = 0; row < col; row++) {
                if (row + 1 == col && s[col] == s[col - 1]) {
                    dp[row][col] = 1;
                    ret++;
                } else if (dp[row + 1][col - 1] == 1 && s[row] == s[col]) {
                    dp[row][col] = 1;
                    ret++;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.countSubstrings("abc") << endl;
    cout << sol.countSubstrings("aaa") << endl;
    cout << sol.countSubstrings("") << endl;
    return 0;
}