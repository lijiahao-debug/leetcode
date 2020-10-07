#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string ret = "";
        int count = k;
        int offset = 2 * k;
        while (count < s.length()) {
            for (int i = count - 1; i >= count - k; i--) {
                ret += s[i];
            }
            for (int i = count; i < count + k & i < s.length(); i++) {
                ret += s[i];
            }
            count += offset;
        }
        for (int i = count - 1; i >= count - k; i--) {
            if (i < s.length()) {
                ret += s[i];
            }
        }
        return ret;
    }
    //todo 可以使用内置reverse函数
};

int main() {
    Solution s;
    cout << s.reverseStr("abcd", 2) << endl;
    return 0;
}