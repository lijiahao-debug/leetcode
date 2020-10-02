#include <iostream>
#include <string>
#include <vector>

using namespace std;

// "00110011" 
// "10101"
class Solution{
public:
    int countBinarySubstrings(string s) {
        int ret = 0;
        int len = s.length();
        if(len == 1)
            return 0;
        
        vector<int> v;        

        int count = 1;
        int i;
        for(i = 0; i < len - 1; i++){
            if(s[i] == s[i+1]){
                count++;
            }else{
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        for(i = 0; i < v.size() - 1; i++){
            ret += min(v[i], v[i+1]);
        }
        return ret;
    }    
};

int main(){
    Solution s;
    cout << s.countBinarySubstrings("00110011") << endl;
    cout << s.countBinarySubstrings("10101") << endl;
    cout << s.countBinarySubstrings("110100") << endl;
}