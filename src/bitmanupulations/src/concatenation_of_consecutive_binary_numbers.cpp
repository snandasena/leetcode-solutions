//
// Created by sajith on 9/23/22.
//

#include "base.h"

class Solution
{
    const int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n)
    {
        long long int ans = 0;
        int curr;
        int cnt;
        for (int i = 1; i <= n; ++i)
        {
            curr = i;
            cnt = 0;
            while (curr)
            {
                ++cnt;
                curr >>= 1;
            }

            ans = (ans << cnt) % MOD;
            ans = (ans + i) % MOD;
        }
        return ans % MOD;
    }
};

int main()
{
    int n = 10;

    cout<< (n&(n-1))<<endl;

    return 0;
}
