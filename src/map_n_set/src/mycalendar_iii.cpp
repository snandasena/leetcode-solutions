//
// Created by sajith on 10/7/22.
//

#include "base.h"

class MyCalendarThree
{
    map<int, int> cal;
public:
    MyCalendarThree()
    {

    }

    int book(int start, int end)
    {
        ++cal[start];
        --cal[end];

        int curr = 0;
        int ans = 0;

        for (const auto &[_, delta]: cal)
        {
            curr += delta;
            ans = max(ans, curr);
        }
        return ans;
    }
};