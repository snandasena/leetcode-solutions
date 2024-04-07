//
// Created by sajit on 30/03/2024.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {

        int ans = 0;

        for (int i = 0; i < nums.size()-k ; ++i)
        {
            vector<int> v(k + 1, 0);
            bool flag = false;
            for (int l = i; l < i+k; ++l)
            {
                ++v[nums[l]];
                if (v[nums[l]] > 1)
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
                ++ans;

        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> v{1,2,1,2,3};
    cout<< sol.subarraysWithKDistinct(v, 2);
}