//
// Created by sajith on 7/21/22.
//


#include "base.h"

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        unordered_map<char, int> ms;
        unordered_map<char, int> mt;

        for (int i = 0; i < s.size(); ++i)
        {
            if (ms.count(s[i]) == 0)
            {
                ms[s[i]] = i;
            }

            if (mt.count(t[i]) == 0)
            {
                mt[t[i]] = i;
            }

            if (ms[s[i]] != mt[t[i]]) return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    cout << boolalpha << solution.isIsomorphic("foo", "bar") << endl;
    return 0;
}