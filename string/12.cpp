#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int thousand_digit = num / 1000;
        int hundred_digit = num % 1000 / 100;
        int ten_digit = num % 1000 % 100 / 10;
        int digit = num % 1000 % 100 % 10;

        string ret = "";
        while (thousand_digit) {
            ret += 'M';
            --thousand_digit;
        }

        if (hundred_digit) {
            if (hundred_digit == 5) {
                ret += 'D';
            } else if (hundred_digit == 9) {
                ret += "CM";
            } else if (hundred_digit == 4) {
                ret += "CD";
            } else if (hundred_digit > 5) {
                ret += 'D';
                while (hundred_digit > 5) {
                    ret += 'C';
                    --hundred_digit;
                }
            } else {
                while (hundred_digit > 0) {
                    ret += 'C';
                    --hundred_digit;
                }
            }
        }
        if (ten_digit) {
            if (ten_digit == 5) {
                ret += 'L';
            } else if (ten_digit == 9) {
                ret += "XC";
            } else if (ten_digit == 4) {
                ret += "XL";
            } else if (ten_digit > 5) {
                ret += 'L';
                while (ten_digit > 5) {
                    ret += 'X';
                    --ten_digit;
                }
            } else {
                while (ten_digit > 0) {
                    ret += 'X';
                    --ten_digit;
                }
            }
        }

        if (digit) {
            if (digit < 4) {
                while (digit > 0) {
                    ret += 'I';
                    --digit;
                }
            } else if (digit == 4) {
                ret += "IV";
            } else if (digit == 5) {
                ret += 'V';
            } else if (digit == 9) {
                ret += "IX";
            } else {
                ret += 'V';
                while (digit > 5) {
                    ret += 'I';
                    --digit;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    // 3999 MMMCMXCIX
    cout << s.intToRoman(3999) << endl;
    // 300 CCC
    cout << s.intToRoman(300) << endl;
    // 777 CCCMLXXVII
    cout << s.intToRoman(777) << endl;

    return 0;
}