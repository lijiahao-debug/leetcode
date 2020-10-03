/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]

Example 2:
Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Example 3:
Input: nums = [7,7,7,7]
Output: [0,0,0,0]
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(vector<T> &v);

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> result;
        result.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] > nums[j])
                    count++;
            }
            result.push_back(count);
        }
        return result;
    }
};

int main() {
    vector<int> v = {8, 1, 2, 2, 3};
    printVector(v);
    Solution s;
    vector<int> result = s.smallerNumbersThanCurrent(v);
    printVector(result);
    return 0;
}

template <typename T>
void printVector(vector<T> &v) {
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
