//
// Created by sajith on 7/24/22.
//


#include "base.h"

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        auto N = static_cast<int >(matrix.size());
        auto M = static_cast<int >(matrix[0].size());
        int mid;
        int l;
        int r;
        for (int i = N - 1; i >= 0; --i)
        {
            if (target >= matrix[i][0])
            {
                l = 0;
                r = M;
                while (l < r)
                {
                    mid = l + (r - l) / 2;
                    if (target == matrix[i][mid]) return true;
                    else if (target < matrix[i][mid])
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};