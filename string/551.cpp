#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int flagA = 0;
        int flagL = 0;
        char last = 0;
        for (char c : s) {
            if (c == 'A') {
                ++flagA;
                if (flagA == 2)
                    return false;
            }
            if (c == 'L' && c == last) {
                ++flagL;
                if (flagL == 2)
                    return false;
            }else{
                flagL = 0;
            }
            last = c;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.checkRecord("LLPPPLL") << endl;
    return 0;
}