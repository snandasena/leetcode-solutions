//
// Created by sajith on 9/3/22.
//

#include "base.h"

class Solution
{
public:
    bool dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return false;
        }

        if (grid[i][j] == 1)
        {
            return true;
        }
        grid[i][j] = 1;
        auto b1 = dfs(grid, i, j - 1);
        b1 &= dfs(grid, i - 1, j);
        b1 &= dfs(grid, i, j + 1);
        b1 &= dfs(grid, i + 1, j);
        return b1;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; ++i)
        {
            for (int j = 0; j < grid[0].size() - 1; ++j)
            {
                if (grid[i][j] == 0 && dfs(grid, i, j))
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
};