
//
// Created by sajith on 8/24/22.
//

#include "base.h"

const auto st = []
{
    unordered_set<long> s;
    s.insert(1);
    long x = 3;
    for (int i = 1; i < 22; ++i)
    {
        s.insert(x);
        x = pow(3, i);
    }
    return s;
}();

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (st.find(n) != st.end())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int x = 3;
    for (int i = 1; i < 21; ++i)
    {
        cout << x << endl;
        x = pow(3, i);
    }
    return 0;
}