
//
// Created by sajith on 7/19/22.
//


#include "base.h"

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});

        if (numRows == 1) return ans;
        ans.push_back({1, 1});

        for (int i = 2; i < numRows; ++i)
        {
            vector<int> v;
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i) v.push_back(1);
                else
                {
                    v.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }

            ans.push_back(v);
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    sol.generate(5);
    return 0;
}