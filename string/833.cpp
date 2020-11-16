#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets) {
        if (S.size() == 0 || indexes.size() == 0) {
            return S;
        }
        map<int, int> m;
        for (int i = 0; i < indexes.size(); i++) {
            m.insert(pair<int, int>(indexes[i], i));
        }

        string ret;
        int index = 0;
        int previous = 0;
        for (auto it : m) {
            index = it.first;
            int coordinate = it.second;
            int len = sources[coordinate].length();
            if (previous < index) {
                ret += S.substr(previous, index - previous);
            }
            if (S.substr(index, len) == sources[coordinate]) {
                ret += targets[coordinate];
            } else {
                ret += S.substr(index, len);
            }
            previous = index + len;
        }
        if (previous < S.size()) {
            ret += S.substr(previous);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    string S = "abcd";
    vector<int> indexes = {0, 2};
    vector<string> sources = {"a", "cd"};
    vector<string> targets = {"eee", "ffff"};
    cout << sol.findReplaceString(S, indexes, sources, targets) << endl;
    S = "vmokgggqzp";
    indexes = {3, 5, 1};
    sources = {"kg", "ggq", "mo"};
    targets = {"s", "so", "bfr"};
    cout << sol.findReplaceString(S, indexes, sources, targets) << endl;
    S = "vmokgggqzp";
    indexes = {1, 3, 5};
    sources = {"mo", "kg", "ggq"};
    targets = {"bfr", "s", "so"};
    cout << sol.findReplaceString(S, indexes, sources, targets) << endl;
    cout << "vbfrssozp" << endl;
    return 0;
}