
//
// Created by sajith on 8/22/22.
//

#include "../base.h"

long taskOfPairing(vector<long> freq)
{
    long ans = 0;
    long rem = 0;

    for (const auto &item: freq)
    {
        if (item == 0)
        {
            rem = 0;
        }
        else
        {
            auto curr = item + rem;
            ans += curr / 2;
            rem = curr % 2;
        }
    }
    return ans;
}

int minOperations(vector<int> arr, int threshold, int d)
{
    auto mx = 200007;
    vector<int> v[mx];

    int cnt;
    for (int i = 0; i < arr.size(); ++i)
    {
        cnt = 0;
        v[arr[i]].push_back(0);

        while (arr[i] > 0)
        {
            arr[i] /= d;
            ++cnt;
            v[arr[i]].push_back(cnt);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < mx; ++i)
    {
        if (v[i].size() >= threshold)
        {
            int move = 0;
            sort(v[i].begin(), v[i].end());

            for (int j = 0; j < threshold; ++j)
            {
                move += v[i][j];
            }

            ans = min(ans, move);
        }
    }
    return ans;

}

int main()
{

}