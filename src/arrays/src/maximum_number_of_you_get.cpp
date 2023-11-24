//
// Created by sajit on 24/11/2023.
//

#include "base.h"


class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        deque<int> q;

        for (const auto &item: piles)
            q.push_back(item);

        int ans = 0;
        while (!q.empty())
        {
            q.pop_back();
            ans += q.back();
            q.pop_back();
            q.pop_front();
        }
        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> v{2, 4, 1, 2, 7, 8};

    cout << sol.maxCoins(v);
}