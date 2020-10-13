#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string real_a, img_a;
        string real_b, img_b;

        int index = a.find('+');
        real_a = a.substr(0, index);
        img_a = a.substr(index + 1, a.size() - index - 2);

        index = b.find('+');
        real_b = b.substr(0, index);
        img_b = b.substr(index + 1, b.size() - index - 2);

        string ret_real, ret_img;
        ret_real = to_string(stoi(real_a) * stoi(real_b) + (-1) * stoi(img_a) * stoi(img_b));

        ret_img = to_string(stoi(real_a) * stoi(img_b) + stoi(real_b) * stoi(img_a)) + 'i';

        return ret_real + "+" + ret_img;
    }
};

int main() {
    Solution sol;
    cout << sol.complexNumberMultiply("1+-1i", "1+1i") << endl;
    return 0;
}