//
// Created by sajith on 11/9/22.
//
#include "base.h"

class StockSpanner
{
    stack<pair<int, int>> v;
public:
    StockSpanner()
    {

    }
    int next(int price)
    {
        int ans = 1;
        while (!v.empty() && v.top().first <= price)
        {
            ans += v.top().second;
            v.pop();
        }
        v.push({price, ans});
        return ans;
    }
};

int main()
{
    StockSpanner stockSpanner;
    stockSpanner.next(100); // return 1
    stockSpanner.next(80);  // return 1
    stockSpanner.next(60);  // return 1
    stockSpanner.next(70);  // return 2
    stockSpanner.next(60);  // return 1
    stockSpanner.next(75);  // return 4
    stockSpanner.next(85);  // return 6
}