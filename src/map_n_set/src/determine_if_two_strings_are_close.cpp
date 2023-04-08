
//
// Created by sajith on 12/2/22.
//

#include "base.h"

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        vector<int> v3(26, 0);
        vector<int> v4(26, 0);

        for (const auto &e: word1)
        {
            ++v1[e - 'a'];
            v2[e - 'a'] = 1;
        }
        for (const auto &e: word2)
        {
            ++v3[e - 'a'];
            v4[e - 'a'] = 1;
        }

        if (v2 != v4)
        {
            return false;
        }

        sort(v1.begin(), v1.end());
        sort(v3.begin(), v3.end());

        return v1 == v3;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha << sol.closeStrings("uau", "ssx");
    return 0;
}