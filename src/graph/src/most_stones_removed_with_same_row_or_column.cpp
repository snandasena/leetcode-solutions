//
// Created by sajith on 11/14/22.
//

#include "base.h"

class Solution
{
    vector<bool> visited;

    void dfs(int idx, vector<vector<int>> &stones)
    {
        visited[idx] = true;
        for (int i = 0; i < stones.size(); ++i)
        {
            if (!visited[i])
            {
                if (stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1])
                {
                    dfs(i, stones);
                }
            }
        }
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        visited.resize(stones.size(), false);
        int cnt = 0;
        for (int i = 0; i < stones.size(); ++i)
        {
            if (!visited[i])
            {
                ++cnt;
                dfs(i, stones);
            }
        }
        return static_cast<int>(stones.size()) - cnt;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v{{0, 0},
                          {0, 1},
                          {1, 0},
                          {1, 2},
                          {2, 1},
                          {2, 2}};


    return 0;
}