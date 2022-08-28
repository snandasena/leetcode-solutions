//
// Created by sajith on 8/28/22.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        auto N = mat.size();
        auto M = mat[0].size();

        for (int k = 0; k < M; ++k)
        {
            int i = 0, j = k;
            for (; i < N && j < M; ++i, ++j)
            {
                cout << mat[i][j] << '\t';
            }
            cout << '\n';

        }
        return mat;
    }
};


int main()
{

    vector<vector<int>> v{{3, 3, 1, 1},
                          {2, 2, 1, 2},
                          {1, 1, 1, 2}};

    Solution sol;
    sol.diagonalSort(v);

    return 0;
}