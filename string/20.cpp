#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for (char c : s) {
            switch (c) {
            case '(':
                temp.push('(');
                break;
            case '{':
                temp.push('{');
                break;
            case '[':
                temp.push('[');
                break;
            case ')':
                if (temp.empty() || '(' != temp.top()) {
                    return false;
                }
                temp.pop();
                break;
            case '}':
                if (temp.empty() || '{' != temp.top()) {
                    return false;
                }
                temp.pop();
                break;
            case ']':
                if (temp.empty() || '[' != temp.top()) {
                    return false;
                }
                temp.pop();
                break;
            default:
                break;
            }
        }
        return temp.empty();
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("]") << endl;
    return 0;
}