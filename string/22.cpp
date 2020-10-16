#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> ret;

public:
    vector<string> generateParenthesis(int n) {
        f("", n, n);
        return ret;
    }

    void f(string s, int left, int right) {
        if (left == 0) {
            while (right) {
                s += ')';
                --right;
            }
            ret.push_back(s);
            return;
        }
        if (left) {
            if (left < right) {
                f(s + '(', left - 1, right);
                f(s + ')', left, right - 1);
            } else {
                f(s + '(', left - 1, right);
            }
        }
        return;
    }
};

int main() {
    Solution sol;
    vector<string> ret = sol.generateParenthesis(3);
    for (string s : ret) {
        cout << s << endl;
    }
    return 0;
}