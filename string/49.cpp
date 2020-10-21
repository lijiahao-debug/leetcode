#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> maps;
        for (auto &str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            maps[temp].push_back(str);
        }
        for (auto &map : maps) {
            ret.push_back(map.second);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    sol.groupAnagrams(strs);
    return 0;
}