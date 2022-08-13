//
// Created by sajith on 8/13/22.
//


#include "base.h"

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        vector<int> v(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; --i)
        {
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                v[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                v[i + j] += v[i + j + 1] / 10;
                v[i + j + 1] %= 10;
            }
        }

        auto itr = v.begin();
        while (*itr == 0 && itr != v.end())
        {
            ++itr;
        }

        string ans;
        while (itr != v.end())
        {
            ans += to_string(*itr);
            ++itr;
        }
        return ans;
    }
};


int main()
{
    return 0;
}