//
// Created by sajith on 9/29/22.
//


#include "base.h"

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int min_indx = 0;
        int mn = INT_MAX;
        for (int i = 0; i < arr.size(); ++i)
        {
            auto l = abs(x - arr[i]);
            if (mn > l)
            {
                mn = l;
                min_indx = i;
            }
        }

        int l = min_indx - 1;
        int r = min_indx + 1;
        vector<int> ans;
        ans.push_back(arr[min_indx]);
        while (ans.size() < k)
        {
            if (l >= 0 && r < arr.size())
            {
                auto low = arr[l];
                auto upper = arr[r];

                if (x - low <= upper - x)
                {
                    ans.push_back(low);
                    --l;
                }
                else
                {
                    ans.push_back(upper);
                    ++r;
                }
            }
            else if (l < 0 && r < arr.size())
            {
                ans.push_back(arr[r]);
                ++r;
            }
            else if (l >= 0 && r >= arr.size())
            {
                ans.push_back(arr[l]);
                --l;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v{0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    for (auto ele: sol.findClosestElements(v, 3, 5))
    {
        cout << ele << '\t';
    }
    return 0;
}