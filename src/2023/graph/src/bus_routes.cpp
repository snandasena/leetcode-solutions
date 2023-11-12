//
// Created by sajit on 12/11/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        unordered_map<int, unordered_set<int>> adgList;

        for (int route = 0; route < routes.size(); ++route)
        {
            for (const auto &stop: routes[route])
            {
                adgList[stop].insert(route);
            }
        }

        unordered_set<int> visited;
        queue<int> que;

        for (const auto &route: adgList[source])
        {
            que.push(route);
            visited.insert(route);
        }

        int cnt = 1;
        while (!que.empty())
        {
            auto size = que.size();
            for (int i = 0; i < size; ++i)
            {
                auto route = que.front();
                que.pop();

                for (const auto &stop: routes[route])
                {
                    if (stop == target)
                        return cnt;

                    for (const auto &nextRoute: adgList[stop])
                    {
                        if (!visited.count(nextRoute))
                        {
                            visited.insert(nextRoute);
                            que.push(nextRoute);
                        }
                    }
                }
            }
            ++cnt;
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> v{{1, 2, 7},
                          {3, 6, 7}};
    sol.numBusesToDestination(v, 1, 6);

}