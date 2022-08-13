//
// Created by sajith on 8/12/22.
//
#include "base.h"

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        auto N = static_cast<int>(grid.size());
        auto M = static_cast<int>(grid.front().size());

        vector<int> ans(M, -1);

        int col_pos;
        int npos;
        for (int col = 0; col < M; ++col)
        {
            col_pos = col;
            npos = -1;
            for (int row = 0; row < N; ++row)
            {
                npos = col_pos + grid[row][col_pos];
                if (npos < 0 || npos >= M || grid[row][npos] != grid[row][col_pos])
                {
                    col_pos = -1;
                    break;
                }
                col_pos = npos;
            }
            ans[col] = col_pos;
        }
        return ans;
    }
};