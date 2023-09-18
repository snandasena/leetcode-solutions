//
// Created by sajit on 18/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < mat.size(); ++i)
        {
            int k = 0;
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (mat[i][j] == 1)
                    k += mat[i][j];
                else
                    break;
            }
            pq.push({k, i});
        }

        vector<int> ans;
        while (k--)
        {
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }

        return ans;
    }
};