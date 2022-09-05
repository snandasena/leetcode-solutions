//
// Created by sajith on 9/3/22.
//

#include "base.h"

class Solution
{
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
        {
            return;
        }
        grid[i][j] = 0;

        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
    }
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i * j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        dfs(grid, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v{{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                          {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                          {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                          {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
                          {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                          {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                          {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                          {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                          {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};

    Solution sol;
    cout << sol.numEnclaves(v) << endl;

    return 0;
}