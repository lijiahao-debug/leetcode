#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP {
public:
    vector<int> getPrefixTable(string &pattern);
    int search(string &text, string &pattern);
};

int main() {
    KMP kmp;
    string s;
    // s = "ABABC";
    s = "AB";

    string text;
    text = "ABAACABABCAC";
    int index = kmp.search(text, s);
    cout << "index = " << index << endl;
    return 0;
}

vector<int> KMP::getPrefixTable(string &pattern) {
    int len = pattern.length();
    vector<int> prefix_table(len);
    prefix_table[0] = 0;
    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[prefix_table[i - 1]])
            prefix_table[i] = prefix_table[i - 1] + 1;
        else
            prefix_table[i] = 0;
        i++;
    }
    i = len - 1;
    while (i > 0) {
        prefix_table[i] = prefix_table[i - 1];
        i--;
    }
    prefix_table[0] = -1;
    return prefix_table;
}

int KMP::search(string &text, string &pattern) {
    if (text.length() < pattern.length())
        return -1;

    vector<int> prefix_table = KMP::getPrefixTable(pattern);
    int i;
    for (i = 0; i < prefix_table.size(); i++) {
        cout << prefix_table[i] << " ";
    }
    cout << endl;

    i = 0;
    int j = 0;

    while (i < text.length()) {
        if (text[i] == pattern[j] && j == pattern.length() - 1)
            return i - j;

        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = prefix_table[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }

    return -1;
}
