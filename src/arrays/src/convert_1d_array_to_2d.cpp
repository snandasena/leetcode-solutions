//
// Created by sajit on 01/09/2024.
//


#include "base.h"

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int rows, int cols)
    {

        if (original.size() != rows * cols)
            return {};

        vector<vector<int>> ans(rows, vector<int>(cols));
        auto itr = original.begin();
        for (unsigned i = 0u; i < rows; ++i)
        {
            std::copy(itr, itr + cols, ans[i].begin());
            itr += cols;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v{1, 2, 3, 4};

    auto res = sol.construct2DArray(v, 2, 2);

    return 0;
}