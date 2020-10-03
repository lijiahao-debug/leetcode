#include <iostream>
#include <string>

using namespace std;

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// IV 4 XL 40 CD 400
// IX 9 XC 90 CM 900
// "MCMXCIV" 1994
// "LVIII" 58
class Solution {
public:
    int romanToInt(string s) {
        int ret;
        int len = s.length();
        ret = 0;
        int i = 0;

        while (i < len - 1) {
            switch (s[i]) {
            case 'I':
                if (s[i + 1] != 'I')
                    ret -= 1;
                else
                    ret += 1;
                break;
            case 'V':
                if (s[i + 1] != 'I' && s[i + 1] != 'V')
                    ret -= 5;
                else
                    ret += 5;
                break;
            case 'X':
                if (s[i + 1] != 'I' && s[i + 1] != 'V' && s[i + 1] != 'X')
                    ret -= 10;
                else
                    ret += 10;
                break;
            case 'L':
                if (s[i + 1] == 'C' || s[i + 1] == 'D' || s[i + 1] == 'M')
                    ret -= 50;
                else
                    ret += 50;
                break;
            case 'C':
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    ret -= 100;
                else
                    ret += 100;
                break;
            case 'D':
                if (s[i + 1] == 'M')
                    ret -= 500;
                else
                    ret += 500;
                break;
            case 'M':
                ret += 1000;
                break;
            default:
                break;
            }
            i++;
        }
        switch (s[i]) {
        case 'I':
            ret += 1;
            break;
        case 'V':
            ret += 5;
            break;
        case 'X':
            ret += 10;
            break;
        case 'L':
            ret += 50;
            break;
        case 'C':
            ret += 100;
            break;
        case 'D':
            ret += 500;
            break;
        case 'M':
            ret += 1000;
            break;
        default:
            break;
        }
        return ret;
    }

    int romanToInt2(string s) {
        int ret = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case 'I':
                tmp1 = 1;
                break;
            case 'V':
                tmp1 = 5;
                break;
            case 'X':
                tmp1 = 10;
                break;
            case 'L':
                tmp1 = 50;
                break;
            case 'C':
                tmp1 = 100;
                break;
            case 'D':
                tmp1 = 500;
                break;
            case 'M':
                tmp1 = 1000;
                break;
            default:
                break;
            }
            if (tmp2 < tmp1) {
                ret -= tmp2;
            } else {
                ret += tmp2;
            }
            tmp2 = tmp1;
        }
        ret += tmp2;
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt2("III") << endl;
    cout << s.romanToInt2("IV") << endl;
    cout << s.romanToInt2("VV") << endl;
    cout << s.romanToInt2("LVIII") << endl;
    cout << s.romanToInt2("MCMXCIV") << endl;
    int a = 1;
    return 0;
}