#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* hints
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
10.     13211311123113112211
*/
class Solution {
public:
    string countAndSay1(int n) {
        string s1 = "1";
        string pre = s1;
        string temp = "";
        int i = 2;
        while (i <= n) {
            int count = 1;
            for (int j = 0; j < pre.length(); j++) {
                if (j + 1 < pre.length() && pre[j] == pre[j + 1]) {
                    ++count;
                } else {
                    temp += to_string(count);
                    temp += pre[j];
                    count = 1;
                }
            }
            pre = temp;
            temp = "";
            ++i;
        }
        return pre;
    }

    // * recursion
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";
        string ret;
        string temp = countAndSay(n - 1);
        int count = 1;
        for (int i = 0; i < temp.size(); i++) {
            if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                ++count;
            } else {
                ret += to_string(count);
                ret += temp[i];
                count = 1;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i <= 10; i++) {
        cout << sol.countAndSay(i) << endl;
    }
}