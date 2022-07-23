//
// Created by sajith on 7/23/22.
//


#include "base.h"

class NumberContainers
{
    map<int, int> mp;
public:
    NumberContainers()
    {

    }

    void change(int index, int number)
    {
        mp[index] = number;
    }

    int find(int number)
    {
        for (const auto &item: mp)
        {
            if (item.second == number) return item.first;
        }
        return -1;
    }
};