#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1 = name.length();
        int len2 = typed.length();
        if (len2 < len1)
            return false;
        int index1 = 0;
        int index2 = 0;
        char previous = name[0];
        while (index1 < len1 && index2 < len2) {
            if (name[index1] != typed[index2] && previous != typed[index2])
                return false;
            if (name[index1] == typed[index2]) {
                previous = name[index1];
                ++index1;
                ++index2;
            }
            if (name[index1] != typed[index2] && previous == typed[index2])
                ++index2;
        }
        if (index1 < len1)
            return false;
        while (index2 < len2) {
            if (previous != typed[index2])
                return false;
            ++index2;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isLongPressedName("alex", "aaleex") << endl;
    return 0;
}