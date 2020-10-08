#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //todo optimize code
    string addStrings(string num1, string num2) {
        string ret = "";
        int len1 = num1.length();
        int len2 = num2.length();
        int index1 = len1 - 1;
        int index2 = len2 - 1;
        int carry = 0;
        while (index1 >= 0 && index2 >= 0) {
            int temp = (num1[index1] - '0') + (num2[index2] - '0') + carry;
            if (temp >= 10) {
                carry = 1;
                ret += temp % 10 + '0';
            } else {
                carry = 0;
                ret += temp + '0';
            }
            --index1;
            --index2;
        }
        while (index1 >= 0) {
            int temp = num1[index1] - '0' + carry;
            if (temp >= 10) {
                carry = 1;
                ret += temp % 10 + '0';
            } else {
                carry = 0;
                ret += temp + '0';
            }
            --index1;
        }
        while (index2 >= 0) {
            int temp = num2[index2] - '0' + carry;
            if (temp >= 10) {
                carry = 1;
                ret += temp % 10 + '0';
            } else {
                carry = 0;
                ret += temp + '0';
            }
            --index2;
        }
        if (carry)
            ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.addStrings("123", "321") << endl;
    cout << s.addStrings("1", "9") << endl;
    cout << s.addStrings("6", "501") << endl;
    return 0;
}