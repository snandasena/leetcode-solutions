//
// Created by sajith on 9/4/22.
//

#include "task_scheduler.h"

int main()
{

    Solution sol;
    vector<char> v{'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    LOG(sol.leastInterval(v, n))<<END;

    return 0;
}