/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string result = "";
        
        int len = S.size();
        vector<string> v;
        int flag = 0;
        for(int i = 0; i < len; i++){
            if(S[i] == ' '){
                v.push_back(S.substr(flag, i-flag));
                flag = i + 1;
            }
        }
        v.push_back(S.substr(flag));
        string temp = "";
        
        for(int i = 0; i < v.size(); i++){
            temp = v[i];
            if(temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u'
            || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U'){
                result += temp;
            }else{
                result.append(temp.substr(1));
                result += temp[0];
            }
            result += "ma";
            for(int j = 0; j < i+1; j++){
                result += 'a';
            }
            result += ' ';
        }
        result.pop_back();
        return result;
    }
};

int main(){
    string s;
    Solution sol;

    s = "I speak Goat Latin";
    string result = sol.toGoatLatin(s);
    cout << result << endl;
}