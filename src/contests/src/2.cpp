//
// Created by sajith on 10/9/22.
//

#include "base.h"

class Solution1
{

public:
    vector<int> findArray(vector<int> &arr)
    {
        if (arr.size() == 1) return arr;

        vector<int> ans(arr.size());
        ans[0] = arr[0];
        int prev = arr[0];

        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] == 0)
            {
                ans[i] = prev;
                prev = 0;
                continue;
            }
            else if (prev == 0)
            {
                ans[i] = arr[i];
                prev = arr[i];
                continue;
            }

            int x = 1;
            auto curr = arr[i];
            int y = 0;
            while ((prev ^ y) != curr)
            {
                if ((prev & x) > 0 && (curr & x) == 0)
                {
                    y += x;
                }
                else if ((prev & x) == 0 && (curr & x) > 0)
                {
                    y += x;
                }
                x <<= 1;
            }
            ans[i] = y;
            prev = curr;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int temp;
        int prev = pref[0];
        for (int i = 1; i < pref.size(); ++i)
        {
            temp = pref[i];
            pref[i] = prev ^ pref[i];
            prev = temp;
        }
        return pref;
    }
};


int main()
{
    Solution solution;
    vector<int> v{5, 2, 0, 3, 1};

    for (const auto &item: solution.findArray(v))
    {
        cout << item << '\t';
    }
    return 0;
}