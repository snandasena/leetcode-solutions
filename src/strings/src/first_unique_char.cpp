
//
// Created by sajith on 8/16/22.
//


#include "base.h"

class Solution
{
    struct Node
    {
        char x;
        int c;
        int i;
    };
public:
    int firstUniqChar2(string s)
    {
        vector<Node> v(26, {'A', 0, -1});

        for (int i = 0; i < s.size(); ++i)
        {
            v[s[i] - 'a'] = {s[i], v[s[i] - 'a'].c + 1, i};
        }

        sort(v.begin(), v.end(), [](const auto &n1, const auto &n2)
             {
                 return n1.i < n2.i;
             }
        );
        for (const auto &node: v)
        {
            if (node.x != 'A' && node.c == 1)
            {
                return node.i;
            }
        }
        return -1;
    }

    int firstUniqChar(string s)
    {
        vector<int> v(26, 0);
        for (const auto &ch: s)
        {
            ++v[ch - 'a'];
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (v[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};