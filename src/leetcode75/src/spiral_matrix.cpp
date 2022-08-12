//
// Created by sajith on 8/12/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        auto rows = static_cast<int>(matrix.size());
        auto cols = static_cast<int>(matrix.front().size());

        int up = 0;
        int down = rows - 1;
        int left = 0;
        int right = cols - 1;

        vector<int> ans;
        ans.reserve(rows * cols - 1);

        while (ans.size() < rows * cols)
        {
            for (int col = left; col <= right; ++col)
            {
                ans.push_back(matrix[up][col]);
            }

            for (int row = up + 1; row <= down; ++row)
            {
                ans.push_back(matrix[row][right]);
            }

            if (up != down)
            {
                for (int col = right - 1; col >= left; --col)
                {
                    ans.push_back(matrix[down][col]);
                }
            }

            if (left != right)
            {
                for (int row = down - 1; row > up; --row)
                {
                    ans.push_back(matrix[row][left]);
                }
            }
            ++left;
            --right;
            ++up;
            --down;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v1{{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};

//    Solution sol;
//    sol.spiralOrder(v);

    vector<int> v;
    v.reserve(10);

    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

    return 0;
}