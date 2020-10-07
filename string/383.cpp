#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (char c : ransomNote)
            ++hash[c - 'a'];

        for (char c : magazine)
            --hash[c - 'a'];
        for (int i : hash) {
            if (i > 0)
                return false;
        }

        return true;
    }
};