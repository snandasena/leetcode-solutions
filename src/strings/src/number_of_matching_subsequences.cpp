//
// Created by sajith on 7/20/22.
//


#include "base.h"

class Solution
{
    bool helper(const string &s, const string &str)
    {
        size_t i = 0;
        for (const auto &item: str)
        {
            i = s.find_first_of(item, i);

            if (i++ == string::npos) return false;
        }
        return true;
    }

public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        for (const auto &item: words)
        {
            if (helper(s, item))
            {
                ++ans;
            }
        }
        return ans;
    }
};


int main()
{
    string s{"abcde"};
    vector<string> v{"a", "bb", "acd", "ace"};

    Solution sol;
    cout << sol.numMatchingSubseq(s, v) << endl;


    return 0;
}
