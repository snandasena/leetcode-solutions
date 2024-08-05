//
// Created by sajit on 05/08/2024.
//

#include "base.h"

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> mp;
        for (const auto &str: arr)
        {
            ++mp[str];
        }

        for (const auto &str: arr)
        {
            if (mp[str] == 1)
                --k;

            if (k == 0)
                return str;
        }

        return "";
    }
};

int main()
{
    vector<string> v{"d", "b", "c", "b", "c", "a"};

    Solution solution;
    cout << solution.kthDistinct(v, 2);
}