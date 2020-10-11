#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int lenA = A.length();
        int lenB = B.length();
        if (lenA != lenB)
            return false;
        if (lenA == 0 || lenA == 1)
            return false;

        int hashAB[26] = {0};
        for (int i = 0; i < lenA; i++) {
            ++hashAB[A[i] - 'a'];
        }
        int flag = false;
        for (int i : hashAB) {
            if (i > 1)
                flag = true;
        }
        for (int i = 0; i < lenB; i++) {
            --hashAB[B[i] - 'a'];
        }
        for (int i : hashAB) {
            if (i)
                return false;
        }
        int count = 0;
        for (int i = 0; i < lenA; i++) {
            if (A[i] != B[i])
                count++;
        }
        if (lenA == 2) {
            if (A[0] == A[1] || count == 2)
                return true;
            else
                return false;
        }
        if (!flag && count == 0)
            return false;
        return count <= 2 ? true : false;
    }
};

int main() {
    Solution sol;
    cout << sol.buddyStrings("", "") << endl;
}