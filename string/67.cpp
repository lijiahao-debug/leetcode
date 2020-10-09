#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int carry = 0;
        int indexA = a.length() - 1;
        int indexB = b.length() - 1;
        while (indexA >= 0 || indexB >= 0 || carry) {
            int x = indexA >= 0 ? a[indexA] - '0' : 0;
            int y = indexB >= 0 ? b[indexB] - '0' : 0;
            int temp = x + y + carry;
            if (temp == 0 || temp == 1) {
                ret += temp + '0';
                carry = 0;
            } else {
                ret += temp - 2 + '0';
                carry = 1;
            }
            --indexA;
            --indexB;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("1010", "1011") << endl;
    return 0;
}