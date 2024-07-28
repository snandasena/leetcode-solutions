//
// Created by sajit on 19/07/2024.
//

#include "base.h"

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> col;
        unordered_map<int, int> row;

        for (int i = 0; i < matrix.size(); ++i)
        {
            int row_min = INT_MAX;
            int indx = 0;
            for (int j = 0; j < matrix[i].size(); ++j)
            {

                if (row_min > matrix[i][j])
                {
                    row_min = matrix[i][j];
                    indx = j;
                    row[i] = row_min;
                }
            }

            col[indx] = max(col[indx], matrix[i][indx]);

        }
    }
};

