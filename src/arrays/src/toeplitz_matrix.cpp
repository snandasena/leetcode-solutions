//
// Created by sajith on 10/31/22.
//


#include "base.h"

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {

        auto N = static_cast<int>(matrix.size());
        auto M = static_cast<int>(matrix[0].size());

        for (int i = 1; i < N; ++i)
        {
            for (int j = 1; j < M; ++j)
            {
                if (matrix[i - 1][j - 1] != matrix[i][j])
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
    vector<vector<int>> v{{18},
                          {66}};

    Solution sol;
    cout << sol.isToeplitzMatrix(v);
    return 0;
}