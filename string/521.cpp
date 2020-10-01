#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int findLUSlength(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();
        if(len_a == len_b && a == b)
            return -1;
        return max(len_a, len_b);
    }
};
