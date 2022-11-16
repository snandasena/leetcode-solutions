//
// Created by sajith on 11/16/22.
//

#include "base.h"

int guess(int);

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;
        int mid;
        int res;
        int ans = -1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            res = guess(mid);

            if (res == 0)
            {
                ans = mid;
                break;
            }
            else if (res == -1)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};