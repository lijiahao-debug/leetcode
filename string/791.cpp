#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        int hash_t[26] = {0};

        for (char i : T) {
            ++hash_t[i - 'a'];
        }
        string ret = "";
        for (int i = 0; i < S.length(); i++) {
            int temp = hash_t[S[i] - 'a'];
            hash_t[S[i] - 'a'] = 0;
            while (temp) {
                ret += S[i];
                --temp;
            }
        }
        for (int i = 0; i < 26; i++) {
            int temp = hash_t[i];
            while (temp) {
                ret += i + 'a';
                --temp;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.customSortString("cba", "abcd") << endl;
    return 0;
}