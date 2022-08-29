//
// Created by sajith on 8/28/22.
//

#include "base.h"

class Solution
{
    int getIndex(vector<int> &v)
    {
        int i = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j] != 0)
            {
                i = max(i, j);
            }
        }
        return i;
    }
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> metal;
        vector<int> grass;
        vector<int> paper;

        int ans = 0;
        for (const auto &item: garbage)
        {
            auto M = count(item.begin(), item.end(), 'M');
            metal.push_back(M);
            auto P = count(item.begin(), item.end(), 'P');
            paper.push_back(P);
            auto G = count(item.begin(), item.end(), 'G');
            grass.push_back(G);

            ans += (M + P + G);
        }

        int i = getIndex(paper);
        for (int j = 0; j < i; ++j)
        {
            ans += travel[j];
        }

        i = getIndex(grass);
        for (int j = 0; j < i; ++j)
        {
            ans += travel[j];
        }

        i = getIndex(metal);
        for (int j = 0; j < i; ++j)
        {
            ans += travel[j];
        }
        return ans;

    }
};

int main()
{
    Solution sol;

    vector<string> s{"MMM","PGM","GP"};
    vector<int> t{3,10};

    cout<<sol.garbageCollection(s, t);

    return 0;
}