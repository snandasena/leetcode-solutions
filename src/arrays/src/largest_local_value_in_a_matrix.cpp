#include "base.h"

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        auto rows = grid.size();
        auto cols = grid[0].size();
        vector<vector<int>> ans(rows - 2);

        for (int i = 0; i < rows - 2; ++i)
        {
            vector<int> curr(cols - 2);
            for (int j = 0; j < cols - 2; ++j)
            {
                int mx = 0;
                mx = max(grid[i][j], mx);
                mx = max(grid[i][j + 1], mx);
                mx = max(grid[i][j + 2], mx);

                mx = max(grid[i + 1][j], mx);
                mx = max(grid[i + 1][j + 1], mx);
                mx = max(grid[i + 1][j + 2], mx);

                mx = max(grid[i + 2][j], mx);
                mx = max(grid[i + 2][j + 1], mx);
                mx = max(grid[i + 2][j + 2], mx);

                curr[j] = mx;
            }

            ans[i] = curr;
        }
        return ans;
    }
};