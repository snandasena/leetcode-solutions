//
// Created by sajith on 8/26/22.
//

#include"base.h"

const unordered_set<string> st = []()
{
    int x = 1;
    unordered_set<string> s;
    s.emplace("1");

    for (int i = 1; i < 31; ++i)
    {
        x <<= 1;
        auto str = to_string(x);
        sort(str.begin(), str.end());
        s.emplace(str);
    }
    return s;
}();

class Solution
{
public:
    bool reorderedPowerOf1(int n)
    {
        auto str = to_string(n);
        sort(str.begin(), str.end());
        return st.find(str) != st.end();
    }
};

int func(int c)
{
    return !((c - 1) & c);
}


int main()
{

    int x = 1;
    for (int i = 1; i < 32; ++i)
    {
        cout << x << " " << func(x) << endl;
        x <<= 1;
    }

    return 0;
}