//
// Created by sajith on 2/12/23.
//

#include "base.h"

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        unordered_map<int, unordered_map<int, unordered_set<int>>> graph;
        vector<int> ans(n, INT_MAX);

        for (const auto &p: redEdges)
        {
            graph[p[0]][p[1]].insert(0); //red
        }

        for (const auto &p: blueEdges)
        {
            graph[p[0]][p[1]].insert(1); //blue
        }

        queue<vector<int>> que;
        vector<vector<bool>> visited(2, vector<bool>(n, false));

        visited[0][0] = true;
        visited[1][0] = true;

        que.push({0, 0});
        que.push({1, 0});

        int path = 0;

        while (!que.empty())
        {
            auto size = que.size();

            for (auto i = 0; i < size; ++i)
            {
                auto top = que.front();
                que.pop();
                ans[top[1]] = min(path, ans[top[1]]);

                for (const auto &[k, x]: graph[top[1]])
                {
                    if(x.find(top[0]) != x.end() && !visited[!top[0]][k])
                    {
                        visited[!top[0]][k] = true;
                        que.push({!top[0], k});
                    }
                }
            }
            ++path;
        }

        for(auto &ele: ans)
        {
            if(ele == INT_MAX)
            {
                ele = -1;
            }
        }

    }
};

int main()
{
    int x = 0;
    cout<<!x<<endl;
}