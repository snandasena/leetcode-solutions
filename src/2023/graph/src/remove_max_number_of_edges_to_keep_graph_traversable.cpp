//
// Created by sajit on 30/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n) : components{n}
    {
        components = n;
        component_size.resize(n + 1, 1);
        representative.resize(n + 1);
        std::iota(representative.begin(), representative.end(), 0);
    }

    int find_representative(int x)
    {
        if (representative[x] == x) return x;

        return representative[x] = find_representative(representative[x]);
    }

    int perform_union(int x, int y)
    {
        x = find_representative(x);
        y = find_representative(y);

        if (x == y) return 0;

        if (component_size[x] > component_size[y])
        {
            component_size[x] += component_size[y];
            representative[y] = x;
        } else
        {
            component_size[y] += component_size[x];
            component_size[x] = y;
        }

        components--;
        return 1;
    }

    bool is_connected()
    {
        return components == 1;
    }

private:

    vector<int> representative;
    vector<int> component_size;
    int components;
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        UnionFind A(n);
        UnionFind B(n);

        int edges_required = 0;
        for (const auto &edge: edges)
        {
            if (edge[0] == 3)
                edges_required += (A.perform_union(edge[1], edge[2]) | B.perform_union(edge[1], edge[2]));
        }

        for (const auto &edge: edges)
        {
            if (edge[0] == 1)
            {
                edges_required += A.perform_union(edge[1], edge[2]);
            } else if (edge[0] == 2)
            {
                edges_required += B.perform_union(edge[1], edge[2]);
            }
        }

        if (A.is_connected() && B.is_connected())
            return edges.size() - edges_required;

        return -1;
    }
};

int main()
{
    Solution sol;

    int n = 4;
    vector<vector<int>> v{{3, 1, 2},
                          {3, 2, 3},
                          {1, 1, 3},
                          {1, 2, 4},
                          {1, 1, 2},
                          {2, 3, 4}};
    cout << sol.maxNumEdgesToRemove(n, v);

}