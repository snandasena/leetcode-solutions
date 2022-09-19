//
// Created by sajith on 9/15/22.
//


#include "base.h"

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &v)
    {
        vector<int> ans;
        if (v.size() % 2 == 1)
        {
            return ans;
        }
        sort(v.begin(), v.end());
        if (v[0] == 0 && v[1] != 0)
        {
            return ans;
        }

        unordered_map<int, int> mp;

        return ans;
    }
};

int main()
{
    Solution sol;

}