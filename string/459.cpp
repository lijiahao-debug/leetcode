#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // brute force
    bool repeatedSubstringPattern1(string s) {
        int len = s.length();
        if (len < 2)
            return false;
        vector<int> v;
        for (int i = 1; i < len; i++) {
            if (s[0] == s[i])
                v.push_back(i);
        }
        bool flag;
        string temp;
        for (int i : v) {
            temp = s.substr(0, i);
            flag = true;
            for (int j = i; j < len; j = j + i) {
                if (temp != s.substr(j, i))
                    flag = false;
            }
            if (flag)
                return true;
        }
        return false;
    }
    //! time limit exceeded
    bool repeatedSubstringPattern2(string s) {
        int len = s.length();
        if (len < 2)
            return false;
        int n = 2;
        int min = len / n;
        while (min) {
            string temp = s.substr(0, min);
            string repeated = "";
            for (int i = 0; i < n; i++) {
                repeated += temp;
            }
            if (s.compare(repeated) == 0)
                return true;
            ++n;
            min = len / n;
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, s.length() * 2 - 2).find(s) != -1;
    }
};

int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("abab") << endl;
    cout << s.repeatedSubstringPattern("ababab") << endl;
    cout << s.repeatedSubstringPattern("abcabcabc") << endl;
    cout << s.repeatedSubstringPattern("abacabacabac") << endl;
    cout << s.repeatedSubstringPattern("abcab") << endl;

    string str = "umoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypad";
    cout << s.repeatedSubstringPattern1(str) << endl;
    cout << s.repeatedSubstringPattern(str) << endl;
    return 0;
}