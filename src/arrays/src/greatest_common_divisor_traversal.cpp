//
// Created by sajit on 25/02/2024.
//
# include "base.h"

struct DSU
{
    vector<int> dsu;
    vector<int> size;

    DSU(int N)
    {
        dsu.resize(N + 1);
        size.resize(N + 1, 1);
        iota(dsu.begin(), dsu.end(), 0);
    }

    int find(int x)
    {
        return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
    }

    void merge(int x, int y)
    {
        auto fx = find(x);
        auto fy = find(y);

        if (fx == fy) return;

        if (size[fx] > size[fy])
            swap(fx, fy);
        dsu[fx] = fy;

        size[fy] += size[fx];
    }

};

class Solution
{
public:
    int MAX = 100000;

    bool canTraverseAllPairs(vector<int> &nums)
    {
        int N = nums.size();
        vector<bool> has(MAX + 1, false);

        for (const auto &item: nums)
            has[item] = true;

        if (N == 1) return true;

        if (has[1])
            return false;

        vector<int> sieve(MAX + 1, 0);
        for (int d = 2; d <= MAX; ++d)
        {
            if (sieve[d] == 0)
            {
                for (int v = d; v <= MAX; v += d)
                {
                    sieve[v] = d;
                }
            }
        }

        DSU dsu(2 * MAX + 1);
        for (const auto &x: nums)
        {
            int val = x;
            while (val > 1)
            {
                int prime = sieve[val];
                int root = prime + MAX;

                if (dsu.find(root) != dsu.find(x))
                {
                    dsu.merge(root, x);
                }

                while (val % prime == 0)
                {
                    val /= prime;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= MAX; ++i)
        {
            if (has[i] && dsu.find(i) == i)
            {
                ++cnt;
            }
        }

        return cnt == 1;

    }
};