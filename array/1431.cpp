// 1431. Kids With the Greatest Number of Candies

/* Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
*/
#include <vector>
#include <iostream>
using namespace std;
#include <algorithm>


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        result.reserve(candies.size());

        // int max = candies[0];
        // for(int i = 1; i < candies.size(); i++){
        //     if(candies[i] > max)
        //         max = candies[i];
        // }

        int max = *max_element(candies.begin(), candies.end());
        // cout << "max " << max << endl;

        for(int i = 0; i < candies.size(); i++){
            if((max - candies[i]) <= extraCandies){
                result.push_back(true);
            }else{
                result.push_back(false);
            }       
        }

        return result;
    }
};
template<typename T>
void printVector(vector<T> & v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " "; 
    }
    cout << endl;
}

int main(){
    vector<int> candies = {2,3,5,1,3};
    printVector(candies);
    Solution s;
    int extraCandies = 0;
    cout << "enter extraCandies" << endl;
    cin >> extraCandies;
    vector<bool> result = s.kidsWithCandies(candies, extraCandies);
    printVector(result);
    return 0;
}

