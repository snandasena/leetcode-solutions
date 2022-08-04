
//
// Created by sajith on 8/4/22.
//

#include "base.h"

class Solution
{
    using lli = long long int;

    int next(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            int i = n % 10;
            n /= 10;
            sum += i * i;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = next(n);

        while (fast != 1 && fast != slow)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};

int main()
{
    Solution solution;
    cout << boolalpha << solution.isHappy(20) << endl;
    return 0;
}