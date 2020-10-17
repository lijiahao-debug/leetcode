#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int score(string &S, int l, int r) {
        if (r - l == 1) {
            return 1;
        }
        int count = 0;
        for (int i = l; i < r; i++) {
            if (S[i] == '(') {
                ++count;
            }
            if (S[i] == ')') {
                --count;
            }
            if (count == 0) {
                return score(S, l, i) + score(S, i + 1, r);
            }
        }
        return 2 * score(S, l + 1, r - 1);
    }

public:
    /* recursion 
     best case ()()()...()()() O(n)
     worst case (((((...)))))  O(n^2)
    */
    int scoreOfParentheses1(string S) {
        return score(S, 0, S.size() - 1);
    }
    /* count 
        O(n)
    */
    int scoreOfParentheses(string S) {
        int d = -1;
        int ret = 0;
        for (int i = 0; i < S.size(); i++) {
            d += S[i] == '(' ? 1 : -1;
            if (S[i] == '(' && S[i + 1] == ')') {
                ret += 1 << d;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.scoreOfParentheses("()()()()()") << endl;
    cout << sol.scoreOfParentheses("((()))") << endl;
    cout << sol.scoreOfParentheses("(()())") << endl;
    return 0;
}