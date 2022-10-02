//
// Created by sajith on 10/2/22.
//
#include "base.h"

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int n1 = 0;
        int x = num1;
        int bits = 0;
        while (x)
        {
            if ((x & 1) == 1)
            {
                ++n1;
            }
            x >>= 1;
            ++bits;
        }

        x = num2;
        int n2 = 0;
        int bits2 = 0;
        while (x)
        {
            if ((x & 1) == 1)
            {
                ++n2;
            }
            x >>= 1;
            ++bits2;
        }

        if (n2 == n1)return num1;

        else if (n1 > n2)
        {
            int ans = 0;
            x = (1 << (bits - 1));

            while (n2 > 0)
            {
                if ((x & num1) != 0)
                {
                    ans += x;
                    --n2;
                }
                x >>= 1;
            }
            return ans;

        }
        else
        {
            int ans = num1;
            n2 -= n1;
            x = 1;
            while (n2 > 0)
            {
                if ((x& num1) == 0)
                {
                    ans |= x;
                    --n2;
                }
                x <<= 1;
            }
            return ans;
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.minimizeXor(65, 84);
//
//    cout<< (26 &16)<<endl;
    return 0;
}