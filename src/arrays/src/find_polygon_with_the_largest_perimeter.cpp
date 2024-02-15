//
// Created by sajit on 15/02/2024.
//

#include "base.h"

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        // 1, 1, 2, 3, 5, 12, 50,

        long long ans = -1;
        long long prev = 0;
        for (auto num: nums)
        {
            if (num < prev)
            {
                ans = num + prev;
            }
            prev += num;
        }

        return ans;
    }
};

int main()
{

    Solution solution;
    vector<int> vec{5, 5, 5};
    cout << solution.largestPerimeter(vec);
}
