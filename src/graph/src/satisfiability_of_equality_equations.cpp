//
// Created by sajith on 9/26/22.
//

#include "base.h"


struct DSU
{
    vector<char> parents;
    vector<int> rank;

    DSU()
    {
        parents.reserve(26);
        for (int i = 'a'; i <= 'z'; ++i)
        {
            parents.push_back(i);
        }
        rank.resize(26, 0);
    }

    char Find(char u)
    {
        if (parents[u - 'a'] == u)
        {
            return u;
        }
        return parents[u - 'a'] = Find(parents[u - 'a']);
    }

    void Union(int u, int v)
    {
        auto x = Find(u);
        auto y = Find(v);
        if (rank[x - 'a'] > rank[y - 'a'])
        {
            parents[y - 'a'] = x;
        }
        else if (rank[x - 'a'] < rank[y - 'a'])
        {
            parents[x - 'a'] = y;
        }
        else
        {
            parents[x - 'a'] = y;
            ++rank[y - 'a'];
        }
    }

};


class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU dsu;
        for (const auto &eq: equations)
        {
            if (eq[1] == '=')
            {
                dsu.Union(eq[0], eq[3]);
            }
        }

        for (const auto &eq: equations)
        {
            if (eq[1] == '!')
            {
                auto x = dsu.Find(eq[0]);
                auto y = dsu.Find(eq[3]);
                if (x == y)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{

    vector<int> v;
    v.reserve(10);

    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

}