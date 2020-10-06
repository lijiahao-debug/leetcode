#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26] = {0};
        for (char c : s)
            ++hash[c - 'a'];
        int min_index = s.length();
        for (int i = 0; i < 26; i++) {
            if (hash[i] == 1) {
                int temp = s.find(i + 'a');
                if (temp < min_index)
                    min_index = temp;
            }
        }
        return min_index == s.length() ? -1 : min_index;
    }
    //todo use a vector will be easier
};