/*
1313. Decompress Run-Length Encoded List

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].
Example 2:

Input: nums = [1,1,2,3]
Output: [1,3,3]
*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v);

class Solution {
public:
    vector<int> decompressRLElist(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                result.push_back(nums[i + 1]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4};
    printVector(v);
    Solution s;
    vector<int> result = s.decompressRLElist(v);
    printVector(result);
    return 0;
}

void printVector(vector<int> &v) {
    for (auto a : v)
        cout << a << " ";
    cout << endl;
}
