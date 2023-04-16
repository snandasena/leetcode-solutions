//
// Created by sajit on 16/04/2023.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
    const int MOD = 1e9 + 1;

    long long ways(unsigned i, unsigned target_indx, const vector<string> &words, const string &target,
                   vector<vector<long long >> &memo, const vector<vector<int>> &occ)
    {
        if (target_indx == target.length())
            return 1;
        else if (i == words[0].length())
            return 0;
        else if (memo[i][target_indx] != -1)
            return memo[i][target_indx];

        auto res = ways(i + 1, target_indx, words, target, memo, occ);
        auto ch = target[target_indx];
        res += (ways(i + 1, target_indx + 1, words, target, memo, occ) % MOD) * occ[i][ch - 'a'];
        memo[i][target_indx] = res % MOD;
        return memo[i][target_indx];
    }

public:
    int numWays(vector<string> &words, string target)
    {
        vector<vector<int>> occ(words[0].size(), vector<int>(26, 0));
        for (const auto &w: words)
        {
            for (unsigned i = 0; i < w.size(); ++i)
            {
                occ[i][w[i] - 'a'] += 1;
            }
        }

        vector<vector<long long >> memo(words[0].size(), vector<long long>(target.size(), -1));
        return ways(0, 0, words, target, memo, occ) % MOD;
    }
};


int main()
{

    vector<string> words{"acca", "bbbb", "caca"};
    string target = "aba";

    Solution sol;
    cout << sol.numWays(words, target);

}