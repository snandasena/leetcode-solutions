//
// Created by sajith on 10/2/22.
//

#include "../base.h"

class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        long ans = 0;
        for (int i = 0; i < grid.size() - 2; ++i)
        {
            for (int j = 0; j < grid[i].size() - 2; ++j)
            {
                long x = grid[i][j];
                long y = grid[i][j + 1];
                long z = grid[i][j + 2];

                long a = grid[i + 1][j + 1];

                long p = grid[i + 2][j];
                long q = grid[i + 2][j + 1];
                long r = grid[i + 2][j + 2];

                auto sum = (x + y + z + a + p + q + r);
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};

int main()
{

    Solution solution;

    vector<vector<int>> v{{520626, 685427, 788912, 800638, 717251, 683428},
                          {23602,  608915, 697585, 957500, 154778, 209236},
                          {287585, 588801, 818234, 73530,  939116, 252369}};

//    cout << "ANS\n";
    cout << solution.maxSum(v);
}