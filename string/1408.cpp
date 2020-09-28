/*
Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for(int i = 0; i < words.size(); i++){
            int len1 = words[i].length();
            for(int j = 0; j < words.size(); j++){
                int len2 = words[j].length();
                bool flag =false;
                if(i != j & len1 < len2){
                    for(int k = 0; k < len2; k++){
                        if(words[i] == words[j].substr(k, len1)){
                            result.push_back(words[i]);
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
        }
        return result;
    } 
};

int main(){
    Solution s;
    vector<string> v;
    vector<string> result;

    v.push_back("mass");
    v.push_back("as");
    v.push_back("hero");
    v.push_back("superhero");
    result = s.stringMatching(v);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    // ["leetcoder","leetcode","od","hamlet","am"]


    return 0;
}