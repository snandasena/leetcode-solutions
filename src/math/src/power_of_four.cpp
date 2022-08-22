//
// Created by sajith on 8/22/22.
//

#include "base.h"

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        long x = 1;
        for (int i = 0; i < 16; ++i)
        {
            if (n == x)
            {
                return true;
            }
            x <<= 2;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    cout << boolalpha << sol.isPowerOfFour(-64) << endl;
    return 0;
}