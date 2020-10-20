#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // todo: use istringstream
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> maps;

        for (auto &s : paths) {
            size_t index = s.find(" ");
            string path = s.substr(0, index);
            string remainder = s.substr(index + 1);
            index = remainder.find(" ");
            while (index != string::npos) {
                string temp = remainder.substr(0, index);
                size_t bracket = temp.find("(");
                string fileName = temp.substr(0, bracket);
                string content = temp.substr(bracket + 1, temp.size() - bracket - 2);
                // cout << fileName << "   " << content << endl;

                maps[content].push_back(path + "/" + fileName);

                remainder = remainder.substr(index + 1);
                index = remainder.find(" ");
            }
            if (remainder.size()) {
                size_t bracket = remainder.find("(");
                string fileName = remainder.substr(0, bracket);
                string content = remainder.substr(bracket + 1, remainder.size() - bracket - 2);
                // cout << fileName << "   " << content << endl;
                maps[content].push_back(path + "/" + fileName);
            }
        }
        for (auto &m : maps) {
            if (m.second.size() > 1) {
                ret.push_back(m.second);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> ret;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    ret = sol.findDuplicate(paths);
    paths = {"root/a 1.txt(abcd) 2.txt(efsfgh)", "root/c 3.txt(abdfcd)", "root/c/d 4.txt(efggdfh)"};
    ret = sol.findDuplicate(paths);
    for (auto &v : ret) {
        for (auto &s : v) {
            cout << s << "   ";
        }
        cout << endl;
    }
    return 0;
}