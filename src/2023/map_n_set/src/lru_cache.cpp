//
// Created by sajit on 18/07/2023.
//


#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
    unordered_map<int, int> _map;
    int _capacity;
    deque<int> _que;

public:
    LRUCache(int capacity) : _capacity{capacity} {}

    int get(int key)
    {

        return -1;
    }

    void put(int key, int value)
    {

    }
};

int main()
{
    LRUCache lruCache{2};

    return 0;
}