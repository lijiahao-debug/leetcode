#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        if (paths.empty())
            return NULL;
        if (paths.size() == 1)
            return paths[0][1];

        for (int i = 0; i < paths.size(); i++) {
            bool flag = false;
            string temp = paths[i][1];
            for (int j = 0; j < paths.size(); j++) {
                if (j != i) {
                    if (temp == paths[j][0]) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag == false)
                return temp;
        }
        return NULL;
    }
};

int main() {
    Solution s;

    vector<vector<string>> v;
    vector<string> v1;
    v1.push_back("London");
    v1.push_back("New York");

    vector<string> v2;
    v2.push_back("New York");
    v2.push_back("Lima");

    vector<string> v3;
    v3.push_back("Lima");
    v3.push_back("Sao Paulo");

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    string result = s.destCity(v);
    cout << result << endl;

    return 0;
}