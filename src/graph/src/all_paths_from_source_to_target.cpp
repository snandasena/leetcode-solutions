//
// Created by sajith on 9/6/22.
//

#include "base.h"


class Solution
{
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &graph, int u, vector<int> &path)
    {
        path.push_back(u);
        if (u == graph.size() - 1)
        {
            ans.push_back(path);
        }
        else
        {
            for (const auto &v: graph[u])
            {
                dfs(graph, v, path);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> path;
        dfs(graph, 0, path);
        return ans;
    }
};