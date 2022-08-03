//
// Created by sajith on 8/2/22.
//
#include "base.h"

class Solution
{
public:
    int kthSmallest2(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;

        for (const auto &item: matrix)
        {
            for (const auto &elem: item)
            {
                pq.push(elem);
            }
        }

        while (pq.size() != k)
        {
            pq.pop();
        }

        return pq.top();
    }

    int helper(const vector<vector<int >> &matrix, int val)
    {
        int indx = 0;
        auto N = static_cast<int>(matrix.size());

        int row_num = 0;
        int col_num = N - 1;

        while (row_num < N && col_num >= 0)
        {
            if (val >= matrix[row_num][col_num])
            {
                indx += col_num + 1;
                ++row_num;
            }
            else
            {
                --col_num;
            }
        }
        return indx;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int low = matrix[0][0];
        int high = matrix[matrix.size() - 1].back();
        int mid;
        int rank;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            rank = helper(matrix, mid);

            if (rank < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};