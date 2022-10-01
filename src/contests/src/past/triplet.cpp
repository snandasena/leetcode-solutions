
//
// Created by sajith on 8/7/22.
//
#include "../base.h"

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]] = {i, nums[i]};
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                auto d = nums[j] - nums[i];
                if (d > diff)
                {
                    break;
                }
                else if (d == diff && mp.count(nums[j] + diff) > 0)
                {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution solution;
    vector<int> v{0,1,4,6,7,10};
    int di = 3;
    cout << solution.arithmeticTriplets(v, di);
    return 0;
}