//
// Created by sajith on 9/25/22.
//

#include "base.h"


class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        vector<int> ans;
        for (int i = k; i < nums.size() - k; ++i)
        {

            auto itr1 = nums.begin() + k - i;
            auto itr2 = nums.begin() + i;

            auto b1 = is_sorted(itr1, itr2, less<>());

            auto itr3 = nums.begin() + i + 1;
            auto itr4 = nums.begin() + i + k;
            auto b2 = is_sorted(itr3, itr4, greater<>());

            if (b1 && b2)
            {
                ans.push_back(i);
            }

        }

        return ans;
    }
};

int main()
{

    Solution solution;
    vector<int> v{2, 1, 1, 1, 3, 4, 1};
    for (const auto &item: solution.goodIndices(v, 2))
    {
        cout << item << '\t';
    }


}