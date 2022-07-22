
//
// Created by sajith on 7/22/22.
//


#include "base.h"

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() > t.size()) return false;
        else if (s.size() == t.size() && t != s) return false;
        else if (s == t) return true;

        int i = 0;
        int c = 0;
        for (const auto &item: s)
        {
            while (i < t.size())
            {
                if (item == t[i])
                {
                    ++c;
                    ++i;
                    break;
                }
                ++i;
            }
        }
        return c == s.size();
    }
};

int main()
{
    Solution solution;
    cout << boolalpha << solution.isSubsequence("axc", "ahbgdc");
    return 0;
}