//
// Created by sajith on 10/9/22.
//

#include "base.h"

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        vector<int> v(n + 1);
        int prev = 0;
        for (int i = 0; i < logs.size(); ++i)
        {
            auto id = logs[i][0];
            auto time = logs[i][1];
            v[id] = max(v[id], time - prev);
            prev = time;
        }

        auto mx = max_element(v.begin(), v.end());
        return mx - v.begin();
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> v{{0, 3},
                          {2, 5},
                          {0, 9},
                          {1, 15}};

    cout << sol.hardestWorker(10, v);
    return 0;
}