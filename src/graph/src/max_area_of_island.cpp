//
// Created by sajith on 9/3/22.
//

#include "base.h"


class Solution
{
    void dfs(vector<vector<int>> &grid, int i, int j, int &curr)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
        {
            return;
        }
        if (grid[i][j] == 1)
        {
            ++curr;
            grid[i][j] = -1;
            dfs(grid, i, j + 1, curr);
            dfs(grid, i, j - 1, curr);
            dfs(grid, i + 1, j, curr);
            dfs(grid, i - 1, j, curr);
        }


    }
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
//        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int curr = 0;
                    dfs(grid, i, j, curr);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};