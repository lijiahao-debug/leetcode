#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int ret = 0;
        int i = 0;
        string temp = "";
        int len = 0;
        while (i <= N) {
            temp = to_string(i);
            len = temp.length();
            if (temp.find('3') >= len && temp.find('4') >= len && temp.find('7') >= len && (temp.find('2') < len || temp.find('5') <= len || temp.find('6') < len || temp.find('9') < len))
                ret++;
            i++;
        }
        return ret;
    }

    //TODO: 不转换为字符串
};

int main() {
    Solution s;
    cout << s.rotatedDigits(20) << endl;

    string abc = "321";
    cout << abc.find('1') << endl;
    return 0;
}