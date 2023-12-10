//
// Created by sajit on 10/12/2023.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<vector<int>> ans(M, vector<int>(N));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};