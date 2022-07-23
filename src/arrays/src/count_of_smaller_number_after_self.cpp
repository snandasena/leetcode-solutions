
//
// Created by sajith on 7/23/22.
//


#include "base.h"

class Solution
{
public:
    vector<int> countSmaller2(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            int c = 0;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] <= nums[j])
                    ++c;
            }

            ans[i] = c;
        }
        return ans;
    }

    void merge(vector<int> &ans, vector<pair<int, int>> &v, int start, int end)
    {
        auto mid = start + (end - start) / 2;
        vector<pair<int, int>> temp(end - start + 1);

        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end)
        {
            if (v[i].first <= v[j].first)
            {
                temp[k] = v[j];
                ++k;
                ++j;
            }
            else
            {
                ans[v[i].second] += end - j + 1;
                temp[k] = v[i];
                ++k;
                ++i;
            }
        }

        while (i <= mid)
        {
            temp[k] = v[i];
            ++k;
            ++i;
        }

        while (j <= end)
        {
            temp[k] = v[j];
            ++k;
            ++j;
        }

        for (int l = start; l <= end; ++l)
        {
            v[l] = temp[l - start];
        }

    }

    void mergesort(vector<int> &ans, vector<pair<int, int>> &v, int start, int end)
    {
        if (start >= end) return;
        auto mid = start + (end - start) / 2;
        mergesort(ans, v, start, mid);
        mergesort(ans, v, mid + 1, end);

        merge(ans, v, start, end);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        auto n = static_cast<int>(nums.size());
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
        {
            v.emplace_back(nums[i], i);
        }

        vector<int> ans(n, 0);
        mergesort(ans, v, 0, n - 1);
        return ans;
    }
};