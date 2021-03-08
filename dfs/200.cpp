#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    DFS(grid, i, j);
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}