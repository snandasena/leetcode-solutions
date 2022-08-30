//
// Created by sajith on 8/30/22.
//

#include "base.h"

class Solution
{
    void transpose(vector<vector<int>> &mat)
    {
        auto N = mat.size();
        for (int i = 0; i < N; ++i)
        {
            for (int j = i; j < N; ++j)
            {
                swap(mat[j][i], mat[i][j]);
            }
        }
    }

    void reflect(vector<vector<int>> &mat)
    {
        auto N = mat.size();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N / 2; ++j)
            {
                swap(mat[i][j], mat[i][N - j - 1]);
            }
        }
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reflect(matrix);
    }
};