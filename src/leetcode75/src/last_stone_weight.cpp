//
// Created by sajith on 8/3/22.
//

#include "base.h"

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        int x;
        int y;

        while (pq.size() > 1)
        {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();

            if (x != y)
            {
                pq.push(x - y);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{

    Solution sol;
    vector<int> v{2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeight(v);

    return 0;
}