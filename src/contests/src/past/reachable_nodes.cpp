//
// Created by sajith on 8/7/22.
//


#include "../base.h"

class Solution
{
    int ans = 0;
    vector <vector<int>> adj;
    vector<bool> visited;
    void dfs(int u, int i = 0)
    {
        for (const auto &item: adj[u])
        {
            if (item == i || visited[item]) continue;
            dfs(item, u);
        }
        ++ans;
    }
public:
    int reachableNodes(int n, vector <vector<int>> &edges, vector<int> &restricted)
    {
        adj.resize(n);
        for (const auto &edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        visited.resize(n, false);
        for (const auto &item: restricted)
        {
            visited[item] = true;
        }
        dfs(0);
        return ans;
    }
};

int main()
{
    vector <vector<int>> E{{0, 1},
                           {1, 2},
                           {3, 1},
                           {4, 0},
                           {0, 5},
                           {5, 6}};

    vector<int> R{4, 5};

    Solution solution;
    cout << solution.reachableNodes(7, E, R);
    return 0;
}