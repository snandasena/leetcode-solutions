
//
// Created by sajith on 10/21/22.
//

#include "base.h"

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                if (abs(mp[nums[i]] - i) <= k)
                {
                    return true;
                }else
                {
                    mp[nums[i]] = i;
                }
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> v{1,0,1,1};

    cout<<boolalpha<<sol.containsNearbyDuplicate(v, 1);
}