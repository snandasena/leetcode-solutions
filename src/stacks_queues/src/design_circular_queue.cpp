
//
// Created by sajith on 9/25/22.
//
#include "base.h"

class MyCircularQueue
{
    int cnt;
    list<int> Q;
public:
    MyCircularQueue(int k) : cnt{k}
    {

    }

    bool enQueue(int value)
    {
        if (cnt > Q.size())
        {
            Q.push_back(value);
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (!Q.empty())
        {
            Q.pop_front();
            return true;
        }
        return false;
    }

    int Front()
    {
        if (Q.empty())
        {
            return -1;
        }

        return Q.front();
    }

    int Rear()
    {
        if (Q.empty())
        {
            return -1;
        }
        return Q.back();
    }

    bool isEmpty()
    {
        return Q.empty();
    }

    bool isFull()
    {
        return Q.size() == cnt;
    }
};


int main()
{
    MyCircularQueue myCircularQueue{3};
    myCircularQueue.enQueue(1); // return True
    myCircularQueue.enQueue(2); // return True
    myCircularQueue.enQueue(3); // return True
    myCircularQueue.enQueue(4); // return False
    myCircularQueue.Rear();     // return 3
    myCircularQueue.isFull();   // return True
    myCircularQueue.deQueue();  // return True
    myCircularQueue.enQueue(4); // return True
    myCircularQueue.Rear();

    return 0;
}