//
// Created by sajith on 10/11/22.
//

#include "base.h"

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int first = INT_MAX;
        int second = INT_MAX;

        for (const auto &ele: nums)
        {
            if (ele <= first)
            {
                first = ele;
            }
            else if (ele <= second)
            {
                second = ele;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    Solution sol;
    vector<int> v{5, 4, 1, 2, 3};

    cout << boolalpha << sol.increasingTriplet(v);
}