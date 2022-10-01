//
// Created by sajith on 10/1/22.
//
#include "base.h"

class Solution
{
public:
    bool equalFrequency(string word)
    {
        vector<int> mp(26, 0);
        for (const auto &item: word)
        {
            ++mp[item - 'a'];
        }

        vector<int> v;
        for (const auto &item: mp)
        {
            if (item != 0)
            {
                v.push_back(item);
            }
        }
        sort(v.begin(), v.end());

        if ((v[0] == 1 && v.back() == 1) || v.size() == 1)
        {
            return true;
        }

        for (int i = 0; i < v.size(); ++i)
        {
            --v[i];
            bool flag = false;
            for (int j = 0; j < v.size() - 1; ++j)
            {
                if (j == i && v[j] == 0)
                {
                    continue;
                }
                if (v[j] != v[j + 1])
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                return true;
            }
            ++v[i];
        }
        return false;
    }
};


int main()
{
    Solution solution;
    cout << boolalpha << solution.equalFrequency("ddaccb");
}