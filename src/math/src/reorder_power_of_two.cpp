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
    bool reorderedPowerOf2(int n)
    {
        auto str = to_string(n);
        sort(str.begin(), str.end());
        return st.find(str) != st.end();
    }
};

int main()
{
    Solution s;
    cout << boolalpha << s.reorderedPowerOf2(16);
    return 0;
}