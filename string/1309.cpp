/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"
Example 3:

Input: s = "25#"
Output: "y"
Example 4:

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";

        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '#') {
                result.pop_back();
                result.pop_back();

                int temp = stoi(s.substr(i - 2, 2));
                result.push_back('a' + temp - 1);
            } else {
                int temp = s[i] - 48;
                result.push_back('a' + temp - 1);
            }
        }

        return result;
    }
    string freqAlphabets1(string s) {
        string result = "";

        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (i + 2 < len && s[i + 2] == '#') {
                int temp = stoi(s.substr(i, 2));
                result += 'a' + temp - 1;
                i += 2;
            } else {
                result += s[i] - 49 + 'a';
            }
        }

        return result;
    }
};

int main() {

    Solution sol;
    string s;
    string result;
    s = "10#11#12";
    result = sol.freqAlphabets1(s);
    cout << result << endl;
    s = "1326#";
    result = sol.freqAlphabets1(s);
    cout << result << endl;
    s = "25#";
    result = sol.freqAlphabets1(s);
    cout << result << endl;
    s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
    result = sol.freqAlphabets1(s);
    cout << result << endl;

    return 0;
}