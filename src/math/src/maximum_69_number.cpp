//
// Created by sajith on 11/7/22.
//


#include "base.h"

class Solution
{
public:
    int maximum69Number1(int num)
    {
        vector<int> v;
        while (num > 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }

        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (v[i] == 6)
            {
                v[i] = 9;
                break;
            }
        }

        int ans = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            ans += v[i];
            ans *= 10;
        }
        return ans / 10;
    }

    int maximum69Number(int num)
    {
        string n = to_string(num);
        for (auto &ch: n)
        {
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        }

        return stoi(n);
    }
};

int main()
{
    int n = 6966;
    Solution sol;
    cout << sol.maximum69Number(n);
}