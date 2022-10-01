//
// Created by sajith on 8/14/22.
//

#include "../base.h"

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        auto rows = grid.size();
        auto cols = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < rows - 2; ++i)
        {
            vector<int> curr;
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

                curr.push_back(mx);
            }

            ans.push_back(curr);
        }
        return ans;
    }
};

int main()
{

    Solution solution;

    vector<vector<int>> v{{9, 9, 8, 1},
                          {5, 6, 2, 6},
                          {8, 2, 6, 4},
                          {6, 2, 2, 2}};

    solution.largestLocal(v);
    return 0;
}