
//
// Created by sajith on 8/31/22.
//


#include "base.h"

class Solution
{
    void dfs(vector<vector<int>> &heights, int i, int j, int prev, vector<vector<bool>> &ocean)
    {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || heights[i][j] < prev || ocean[i][j])
        {
            return;
        }
        ocean[i][j] = true;

        dfs(heights, i, j + 1, heights[i][j], ocean);
        dfs(heights, i + 1, j, heights[i][j], ocean);
        dfs(heights, i - 1, j, heights[i][j], ocean);
        dfs(heights, i, j - 1, heights[i][j], ocean);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        auto N = heights.size();
        auto M = heights[0].size();

        vector<vector<bool>> pacific(N, vector<bool>(M, false));
        vector<vector<bool>> atlantic(N, vector<bool>(M, false));

        for (int i = 0; i < M; ++i)
        {
            dfs(heights, 0, i, -1, pacific);
            dfs(heights, N - 1, i, -1, atlantic);
        }

        for (int i = 0; i < N; ++i)
        {
            dfs(heights, i, 0, -1, pacific);
            dfs(heights, i, M- 1, -1, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v{{1, 2, 2, 3, 5},
                          {3, 2, 3, 4, 4},
                          {2, 4, 5, 3, 1},
                          {6, 7, 1, 4, 5},
                          {5, 1, 1, 2, 4}};

    Solution sol;
    sol.pacificAtlantic(v);

    return 0;
}