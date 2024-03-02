//
// Created by sajit on 02/03/2024.
//
#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<>> pq;
        for (const auto &item: nums)
            pq.push(item * item);

        nums.clear();
        while (!pq.empty())
        {
            nums.push_back(pq.top());
            pq.pop();
        }
        return nums;
    }
};

