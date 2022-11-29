//
// Created by sajith on 11/29/22.
//
#include "base.h"

class RandomizedSet
{
    unordered_map<int, size_t> mp;
    vector<int> container;
public:
    RandomizedSet()
    {

    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        container.push_back(val);
        mp[val] = container.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false;
        }

        int pos = mp[val];
        container[pos] = container[container.size() - 1];
        mp[container[pos]] = pos;
        container.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        return container[rand() % container.size()];
    }
};