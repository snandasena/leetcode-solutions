
//
// Created by sajith on 8/18/22.
//


#include "base.h"

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (const auto &ele: arr)
        {
            ++mp[ele];
        }

        if (mp.size() == 1 || mp.size() == 2)
        {
            return 1;
        }

        priority_queue<int> pq;
        for (const auto &[f, s]: mp)
        {
            pq.push(s);
        }

        int ans = 0;
        auto N = static_cast<int>(arr.size());
        int t = 0;
        while (!pq.empty())
        {
            if (pq.top() >= N / 2)
            {
                return 1;
            }
            else
            {
                t += pq.top();
                pq.pop();
                ++ans;
            }

            if (t >= N / 2)
            {
                break;
            }
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> arr{3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    cout << sol.minSetSize(arr);
    return 0;
}