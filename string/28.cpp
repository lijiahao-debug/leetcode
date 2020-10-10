#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (len1 < len2)
            return -1;
        if (!len2)
            return 0;
        vector<int> pre = prefixTable(needle);
        int i = 0;
        int j = 0;
        while (i < len1) {
            if (j == len2 - 1 && haystack[i] == needle[j])
                return i - j;
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = pre[j];
                if (j == -1) {
                    ++i;
                    ++j;
                }
            }
        }
        if (i == len1 && j == len2 && haystack[i - 1] == needle[j - 1])
            return 1;
        return -1;
    }
    vector<int> prefixTable(string needle) {
        int len = needle.length();
        vector<int> prefixTable(len);
        prefixTable[0] = 0;
        int i = 1;
        int j = 0;
        while (i < len) {
            if (needle[i] == needle[j]) {
                j++;
                prefixTable[i] = j;
                ++i;
            } else {
                if (j > 0) {
                    j = prefixTable[j - 1];
                } else {
                    prefixTable[i] = j;
                    ++i;
                }
            }
        }
        i = len - 1;
        while (i > 0) {
            prefixTable[i] = prefixTable[i - 1];
            i--;
        }
        prefixTable[0] = -1;
        return prefixTable;
    }
};

int main() {
    Solution sol;
    cout << sol.strStr("aabaaabaaac", "aabaaac") << endl;
    return 0;
}