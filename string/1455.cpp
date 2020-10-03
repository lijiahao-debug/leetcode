/*
Given a sentence that consists of some words separated by a single space, and a searchWord.

You have to check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).

If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string S is any leading contiguous substring of S.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ret = 1;
        int len = sentence.size();
        int len2 = searchWord.size();
        vector<string> v;
        int index = 0;
        string temp = "";
        for (int i = 0; i < len; i++) {
            if (sentence[i] == ' ') {
                temp = sentence.substr(index, i - index);
                if (searchWord == temp.substr(0, len2)) {
                    return ret;
                }
                index = i + 1;
                ret++;
            }
        }
        if (searchWord == sentence.substr(index, len2))
            return ret;
        return -1;
    }
};

int main() {
    Solution sol;
    string sentence;
    string searchWord;
    sentence = "i am tired";
    searchWord = "you";
    cout << sol.isPrefixOfWord(sentence, searchWord) << endl;
    sentence = "i love eating burger";
    searchWord = "burg";
    cout << sol.isPrefixOfWord(sentence, searchWord) << endl;
}
