//
// Created by sajit on 24/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (const auto &item: stones)
            pq.push(item);

        while (pq.size() >= 2)
        {
            auto e1 = pq.top();
            pq.pop();
            auto e2 = pq.top();
            pq.pop();
            if (e1 != e2)
                pq.push(e1 - e2);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    Solution sol;
    vector<int> v{2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeight(v) << endl;
}