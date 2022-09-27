//
// Created by sajith on 9/27/22.
//

#include "base.h"


class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int N = dominoes.size();
        vector<int> forces(N);

        int force = 0;
        for (int i = 0; i < N; ++i)
        {
            if (dominoes[i] == 'R')
            {
                force = N;
            }
            else if (dominoes[i] == 'L')
            {
                force = 0;
            }
            else
            {
                force = max(force - 1, 0);
            }
            forces[i] += force;
        }
        force = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            if (dominoes[i] == 'L')
            {
                force = N;
            }
            else if (dominoes[i] == 'R')
            {
                force = 0;
            }
            else
            {
                force = max(force - 1, 0);
            }

            forces[i] -= force;
        }
        string ans;
        for (const auto &ele: forces)
        {
            ans += ele > 0 ? 'R' : ele < 0 ? 'L' : '.';
        }
        return ans;
    }
};
