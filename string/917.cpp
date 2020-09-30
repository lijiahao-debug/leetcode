#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string reverseOnlyLetters(string S) {
        //S 33-122 
        string ret = "";
        int len = S.length();
        int i = 0;
        int j = len -1;
        while(i < len){
            // a-z 97-122 A-Z 65-90
            if(S[i] < 65 || (S[i] > 90 && S[i] < 97)){
                //S[i] is not a letter
                ret += S[i++];
            }else if(S[j] < 65 || (S[j] > 90 && S[j] < 97)){
                j--;
            }else{
                ret += S[j--];
                i++;
            }
        }
        return ret;
    }
};

int main(){
    cout << "a=" << (int)'a' << endl;
    cout << "z=" << (int)'z' << endl;
    cout << "A=" << (int)'A' << endl;
    cout << "Z=" << (int)'Z' << endl;
}