//
// Created by sajit on 10/06/2023.
//

class Solution
{
    using ll = long long;

    ll get_sum(int index, ll val, int n)
    {
        ll count = 0;

        if (val > index)
            count += (val + val - index) * (index + 1) / 2;
        else
            count += (val + 1) * val / 2 + index - val + 1;


        if (val >= n - index)
            count += (val + val - n + 1 + index) * (n - index) / 2;
        else
            count += (val + 1) * val / 2 + n - index - val;

        return count - val;
    }


public:
    int maxValue(int n, int index, int maxSum)
    {
        ll left = 1;
        ll right = maxSum;
        ll mid;
        while (left < right)
        {
            mid = (left + right + 1) / 2;
            if (get_sum(index, mid, n) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return static_cast<int>(left);
    }
};