/*
1108. Defanging an IP Address
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string defangIPaddr1(string address) {
        regex dot_re("\\.");
        vector<string> v(sregex_token_iterator(address.begin(), address.end(), dot_re, -1), sregex_token_iterator());

        string result;
        for (auto &&s : v) {
            result.append(s).append("[.]");
            // cout << s << "\n";
        }
        result.erase(result.size() - 3, 3);
        return result;
    }
    string defangIPaddr2(string address) {
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
                i++;
            }
        }
        return address;
    }
    string defangIPaddr3(string address) {
        string temp = "";
        int x = 0;
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                temp += address.substr(x, i - x) + "[.]";
                x = i + 1;
            }
        }
        temp += address.substr(x);
        return temp;
    }
};

int main() {
    Solution s;
    string s1 = s.defangIPaddr3("255.100.50.0");
    cout << s1 << endl;
    return 0;
}